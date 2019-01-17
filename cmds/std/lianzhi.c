

#include <ansi.h>
#include "vocation.h"

inherit F_CLEAN_UP;

#include <medicine.h>


string *msg=({
HIY"$N"+HIY+"���������������ţ�ҩ����ð������������\n"NOR,
HIY"$N"+HIY+"���������������ţ�ҩ����ð������������\n"NOR,
HIY"$N"+HIY+"���������������ţ�ҩ����ð������������\n"NOR,
YEL"һ����ҩ��Ʈ�˳�����$N"+YEL+"��æ��������Щ��\n"NOR,
YEL"$N"+YEL+"������С�ĵ����ţ�ҩ���Ѿ����������ܡ�\n"NOR,
YEL"$N"+YEL+"��ҩ�����˿������ֻ���һЩ���\n"NOR,
WHT"$N"+WHT+"��������ˣ������������ҩ�ġ�\n"NOR,
WHT"$N"+WHT+"�������ҩ�׽����š�\n"NOR,
WHT"$N"+WHT+"������ҩ���ĸ��ӣ������������Ȼ�\n"NOR,
HIC"$N"+HIC+"�ñ��������ᣬ����ҩ���Ͼ�Ҫ�����ˡ�\n"NOR,
HIC"$N"+HIC+"������ѹС��һЩ���������������š�\n"NOR,
RED"$N"+RED+"���������ӣ����û�Ϩ��\n"NOR,

});

int main(object me,string arg)
{
        string name,toolname,msg;
	object tool,*medicine;	
	int lev;
	
	if(!arg||sscanf(arg,"%s with %s",name,toolname)!=2)
	return notify_fail("��ʹ�� lianzhi ҩ������ with ��ҩ���ߡ�\n");
	
	if(!is_leagel_name(name))
	 return 1;
	
	if(!objectp(tool=present(toolname,me)))
		return notify_fail("������û��"+toolname+"������ߡ�\n");
	
	if(!tool->query("yaoshi_tool"))
	return notify_fail("��ֻ����ҩ����ҩ��\n");
        
        if(me->query("vocation")!="ҩʦ")
	  return notify_fail("�㲻��ҩʦ����������ҩ!\n");	
        lev=(int)me->query_skill("bencao-shuli",1);
	if(lev<60)
	return notify_fail("��ı�������̫���ˣ���ô��ҩ��\n");
	
	medicine=all_inventory(tool);
	if(sizeof(medicine)<=0)
	return notify_fail(tool->query("name")+"�����ǿյġ�\n");
		
	if(me->is_busy())
		return notify_fail("�����ں�æ��ЪЪ��!\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	
	if(me->query("gin")<me->query("max_gin")/2)
	 return notify_fail("��ľ�Ѫ̫���ˣ��޷���ҩ��\n");
	if(me->query("kee")<me->query("max_kee")/2)
	 return notify_fail("��ľ�Ѫ̫���ˣ��޷���ҩ��\n");
	if(me->query("sen")<me->query("max_sen")/2)
	 return notify_fail("��ľ�Ѫ̫���ˣ��޷���ҩ��\n");
	
	msg="$N��"+tool->query("name")+"�ŵ��˵��ϣ���������˶ѻ�\n\n"+
	    HIR"$N"+HIR+"������ɿ��ɿ���𽥽�����������\n\n"NOR;
	
	message_vision(msg,me);
	
	me->start_busy(2);
	
	call_out("do_msg",2,me,tool,name,lev,0);
	return 1;
}

void do_msg(object me,object tool,string name,int lev,int times)
{
	if(!me||!tool||environment(tool)!=me)
        return;
      
      if(times==sizeof(msg)){
      	call_out("do_msg2",5,me,tool,name,lev);
      	me->start_busy(2);
      	return;
      }
      message_vision(msg[times]+"\n",me);
      
      if(lev>=250)
      	call_out("do_msg",1,me,tool,name,lev,times+1);
      else
      	call_out("do_msg",1,me,tool,name,lev,times+1);
      me->start_busy(1);
      return;
}

void do_msg2(object me,object tool,string name,int lev)
{
	mapping type;
	string *makeby;	
	object *medicine,new_med;
	int i;
	string longs;
	
	if(!me||!tool||environment(tool)!=me)
        return;
	
	type=([]);
	makeby=({});
		
	medicine=all_inventory(tool);
	if(sizeof(medicine)<=0)
	return;
	for(i=0;i<sizeof(medicine);i++){
	   type+=([ medicine[i]->query("medicine_type/type"):
	            lev*(1+random(7))*medicine[i]->query("medicine_type/gongxiao")/100+
	            random(tool->query("dlev")) ]);
	   // ҩ�Ĺ�Ч=����*ҩ�Ĺ�Ч/100+random(ҩ����Ч�������������������)
	   makeby+=({ medicine[i]->query("name") });
	   if(medicine[i]->query_amount()&&
	      medicine[i]->query_amount()>1)
	      medicine[i]->set_amount(medicine[i]->query_amount()-1);
	   else
           destruct(medicine[i]);
	}
	
	set_medicine_add_type(me,type);	
	
	longs="\n"+name+"���ƺ��ˣ�\n";
	message_vision(longs,me);
	
	new_med=new("/obj/medicine/medicine");
	new_med->set("name",name);
	new_med->set("long","����"+me->name()+"���Ƶġ�"+name+"��\n");
	new_med->set("heal_up",type);
	new_med->set("makeby",makeby);
		
	if(!new_med->move(me)){
	  tell_object(me,"��ĸ��ز����ˣ�\n");
	  new_med->move(environment(me));
	}
	
	me->receive_damage("kee",me->query("max_kee")/2);
	me->receive_damage("gin",me->query("max_gin")/2);
	me->receive_damage("sen",me->query("max_sen")/2);
	
	me->add("vocation_score",random(lev/10));
		
	if(me->query_skill("bencao-shuli",1)>=100)
        me->improve_skill("bencao-shuli",(me->query_int()/3)+me->query("max_pot"));
	else me->improve_skill("bencao-shuli",random(10));
	
    return;
}

int help(object me)
{
write(@HELP
ָ���ʽ : lianzhi <ҩ������> with <����>

���ָ����������һЩҩ���Ȼǰ�����������һ��ҩʦ��
��ҩ�Ĺ��߿��ԴӶ���;���õ�����ο�ְҵ�İ����ļ��Ի����ϸ
��˵����
HELP
    );
    return 1;
}
