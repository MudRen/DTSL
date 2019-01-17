

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg=({
HIY"$N"+HIY+"���������������ţ�ҩ����ð������������\n"NOR,
HIY"$N"+HIY+"���������������ţ�ҩ����ð������������\n"NOR,
HIY"$N"+HIY+"���������������ţ�ҩ����ð������������\n"NOR,
HIR"һ����ҩ��Ʈ�˳�����$N"+HIR+"��æ��������Щ��\n"NOR,
RED"$N"+RED+"������С�ĵ����ţ�ҩζ�Ѿ����������ܡ�\n"NOR,
HIB"$N"+HIB+"�е���Щѣ�Σ���æ��ס�ڱǡ�\n"NOR,
BLU"$N"+BLU+"��������ˣ������������Щ���档\n"NOR,
BLU"$N"+BLU+"�������ҩ�׽����š�\n"NOR,
HIB"$N"+HIB+"������ҩ���ĸ��ӣ��Ѿ���Щվ�������ˡ�\n"NOR,
HIW"$N"+HIW+"��ҩ��ʢ��һЩҩ�����ڵ��ϣ��̵�һ��ð��һ����̡�\n"NOR,
HIR"$N"+HIR+"������ѹС��һЩ���������������š�\n"NOR,
RED"$N"+RED+"���������ӣ����û�Ϩ��\n"NOR,

});

string *levs=({
BLU"΢��"NOR,BLU"��ǿ"NOR,HIB"��ͨ"NOR,HIB"��ǿ"NOR,
HIR"ǿ��"NOR,HIR"��ǿ"NOR,HIM"��ǿ"NOR,HIM"����"NOR,
RED"����"NOR,RED"����"NOR,


});

int main(object me,string arg)
{
        string name,toolname,msg;
	object *medicine,tool;
	int i;
	int lev;
	
	if(!arg||sscanf(arg,"%s with %s",name,toolname)!=2)
	return notify_fail("��ʹ�� liandu ҩ������ with ��ҩ���ߡ�\n");
		
	if(!objectp(tool=present(toolname,me)))
		return notify_fail("������û��"+toolname+"������ߡ�\n");
        
        if(!tool->query("yaoshi_tool"))
	return notify_fail("��ֻ����ҩ��������\n");
        
        if(me->query("vocation")!="ҩʦ")
	  return notify_fail("�㲻��ҩʦ����������ҩ!\n");	
        lev=(int)me->query_skill("poison",1);
	if(lev<60)
	return notify_fail("��Ķ���̫���ˣ���ô������\n");
		
	if(me->is_busy())
		return notify_fail("�����ں�æ��ЪЪ��!\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	
	medicine=all_inventory(tool);
	if(sizeof(medicine)<=0)
	return notify_fail(tool->query("name")+"�����ǿյġ�\n");
	
	for(i=0;i<sizeof(medicine);i++)
	  if(!medicine[i]->query("poison_type"))
	   return notify_fail(medicine[i]->query("name")+"���ܱ��������ƶ�ҩ��\n");
	
	if(me->query("gin")<me->query("max_gin")/2)
	 return notify_fail("��ľ�Ѫ̫���ˣ��޷���ҩ��\n");
	if(me->query("kee")<me->query("max_kee")/2)
	 return notify_fail("��ľ�Ѫ̫���ˣ��޷���ҩ��\n");
	if(me->query("sen")<me->query("max_sen")/2)
	 return notify_fail("��ľ�Ѫ̫���ˣ��޷���ҩ��\n");
	
	if(me->query("liandu_times")>=1000){
	  tell_object(me,"�����ڵĶ��ع��࣬�޷��������ƶ�ҩ�ˣ�\n");
	  me->unconcious();
	  return 1;
	}
	
	msg="$N��"+tool->query("name")+"�ŵ��˵��ϣ���������˶ѻ�\n\n"+
	    HIR"$N"+HIR+"������ɿ��ɿ���𽥽�����������\n\n"NOR;
	
	message_vision(msg,me);
	
	me->start_busy(5);
	
	call_out("do_msg",5,me,tool,name,lev,0);
	return 1;
}

void do_msg(object me,object tool,string name,int lev,int times)
{
	if(!me||!tool||environment(tool)!=me)
        return;
      
      if(times==sizeof(msg)){
      	call_out("do_msg2",5,me,tool,name,lev);
      	me->start_busy(5);
      	return;
      }
      message_vision(msg[times]+"\n",me);
      
      if(lev>=250)
      	call_out("do_msg",5,me,tool,name,lev,times+1);
      else
      	call_out("do_msg",2,me,tool,name,lev,times+1);
      me->start_busy(5);
      return;
}

void do_msg2(object me,object tool,string name,int lev)
{
	
	mapping type;
	string long_msg,*types;
	object *medicine,new_med;
	int i;
	
	if(!me||!tool||environment(tool)!=me)
        return;
	
	type=([]);
	long_msg="\n";
	
	medicine=all_inventory(tool);
	if(sizeof(medicine)<=0)
	return;
	
	for(i=0;i<sizeof(medicine);i++){
	   type+=([ medicine[i]->query("poison_type/type"):
	            lev*medicine[i]->query("poison_type/gongxiao")/100+
	            random(tool->query("dlev")) ]);
	   // ҩ�Ĺ�Ч=����*ҩ�Ĺ�Ч/100+random(ҩ����Ч�������������������)                 
	   if(medicine[i]->query_amount()&&
	      medicine[i]->query_amount()>1)
	      medicine[i]->set_amount(medicine[i]->query_amount()-1);
	   else
           destruct(medicine[i]);
	}
	
	long_msg="����"+me->name()+"���Ƶ�"+name+"��\n";
	long_msg+="��Ч��\n";
		
	types=keys(type);
	for(i=0;i<sizeof(types);i++){
	  long_msg+="��"+types[i]+"����"
	           +levs[type[types[i]]/30>sizeof(levs)-1?sizeof(levs)-1:type[types[i]]/30]+"��\n";
	}
	
	type+=([ "times":lev/10 ]);//��ҩ����������һ��Ϊ 15* lev/10 ��
	type+=([ "names":name ]);//��ҩ����
		
	message_vision("\n"+name+"���ƺ��ˣ�\n",me);
	
	new_med=new("/obj/medicine/poison");
	new_med->set("name",name);
	new_med->set("long",long_msg);
	new_med->set("heal_up",type);
		
	if(!new_med->move(me)){
          tell_object(me,"��ĸ��ز����ˣ�\n");
	  new_med->move(environment(me));
	}
	
	me->add("liandu_times",1);//����һ��������¼��
	
	me->receive_damage("kee",me->query("max_kee")/2);
	me->receive_damage("gin",me->query("max_gin")/2);
	me->receive_damage("sen",me->query("max_sen")/2);
	
	me->add("vocation_score",random(lev/10));
	
	if(me->query_skill("poison",1)>=100)
	me->improve_skill("poison",(me->query_int()/3)+me->query("max_pot"));
	else me->improve_skill("poison",random(10));
	
    return;
}
