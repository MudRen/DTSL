//written by yanyan.
//add color to weapon. :-)  later.
#include <ansi.h>

inherit F_CLEAN_UP;
#include "tiejiang.h"
#include "vocation.h"

#define WIELD 1
#define UNWIELD 2

int change_wield_msg(object me,string name,string msg,int flag);

string *weapon_type=({
"sword","blade","dagger","dart","fork","spear",
"hammer","staff","whip","axe","dagger_poison"});

string *dazao_msg=({
HIY"$N"+HIY+"���������˺���¯�ӵĻ�Խ��Խ���ˣ�\n"NOR,
HIY"$N"+HIY+"���������˺���¯�ӵĻ�Խ��Խ���ˣ�\n"NOR,
HIY"$N"+HIY+"���������˺���¯�ӵĻ�Խ��Խ���ˣ�\n"NOR,
HIR"ֻ������Խ��Խ����$N"+HIR+"��Щ�ܲ����ˡ�\n"NOR,
HIR"ֻ������Խ��Խ����$N"+HIR+"��Щ�ܲ����ˡ�\n"NOR,
HIR"ֻ������Խ��Խ����$N"+HIR+"��Щ�ܲ����ˡ�\n"NOR,
HIB"$N"+HIB+"��ͣ�Ļ�����������ƹƹ���ҵ��ô��ű�����\n"NOR,
HIB"$N"+HIB+"��ͣ�Ļ�����������ƹƹ���ҵ��ô��ű�����\n"NOR,
HIB"$N"+HIB+"��ͣ�Ļ�����������ƹƹ���ҵ��ô��ű�����\n"NOR,
RED"$N"+RED+"��Щ�����������������ӳ��ͨ�졣\n"NOR,
RED"$N"+RED+"��Щ�����������������ӳ��ͨ�졣\n"NOR,
RED"$N"+RED+"��Щ�����������������ӳ��ͨ�졣\n"NOR,
});


int main(object me,string arg)
{
    
	object metirial;
	string met,wp,type;
	int lev,damage,strong;
	mapping mweapon;
	
	string name,msg;
	
	if(!arg)
	return notify_fail("��ʹ�� dazao ԭ������ �������� �������� ��\n"+
	                   "��     dazao -wm ���� ����  ���޸� wield ����ʱ������\n"+
	                   "��     dazao -uwm ���� ���� ���޸� unwield ����ʱ��������\n");
	
	if(sscanf(arg,"-wm %s %s",name,msg)==2)
	  return change_wield_msg(me,name,msg,WIELD);
	
	if(sscanf(arg,"-uwm %s %s",name,msg)==2)
	  return change_wield_msg(me,name,msg,UNWIELD);
	
	if(sscanf(arg,"%s %s %s",met,wp,type)!=3)
		return notify_fail("��ʹ�� dazao ԭ������ �������� �������� ��\n");
	
	if(!is_leagel_name(wp))
	 return 1;
        
        if(me->query("vocation")!="����")
		return notify_fail("�㲻�����������ܴ������!\n");
	
	if(member_array(base_name(environment(me)),tiejiang_here)==-1)
        return notify_fail("�㻹�ǵ�������ȥ��������ɣ�\n");
	
        if(time()>me->query("dazao_busy")&&time()-me->query("dazao_busy")<10+random(5))
	  return notify_fail("��Ъ���ٴ���ɣ�\n");
	
	if(me->query("dazao_poison")){
	  tell_object(me,"�����ڵĶ��ط����ˣ���\n");
	  
	}
	
	if(type=="dagger_poison"&&me->query("vocation_fenzhi")!="poison")
	return notify_fail("�㲻��רְ���춾�������������޷����춾��Ч������\n");
	
	if(strsrch(wp,"/")!=-1)
        return notify_fail("�벻Ҫʹ�����ֹŹֵ����֡�\n");
	if(member_array(type,weapon_type)==-1)
	return notify_fail("���ܴ����������͵ı�����\n");
	if(!objectp(metirial=present(met,me)))
		return notify_fail("������û�����ֶ���!\n");
	if(me->is_busy())
		return notify_fail("�����ں�æ��ЪЪ��!\n");
	if(me->is_fighting())
		return notify_fail("�㻹���ȴ�������˵�ɣ�\n");
	mweapon=metirial->query("weapon");
	if(!mweapon)
		return notify_fail("����"+metirial->name()+"���ܴ������!\n");
	
	/*
	if(!metirial->query("tiejiang_step/shibie"))
	 return notify_fail("�㻹���Ȱ�"+metirial->query("name")+"������ı�����ɣ�\n");
	if(!metirial->query("tiejiang_step/yelian"))
	 return notify_fail("�㻹���Ȱ�"+metirial->query("name")+"�ü���ʦұ���ɣ�\n");
	*/
	lev=(int)me->query_skill("duanzao-jishu",1);
	if(lev<60)
	return notify_fail("��Ķ��켼��̫����޷����������\n");
	if(me->query_str()<30)
	return notify_fail("�������̫���ˣ��޷����������\n");
	
	if(me->query("gin")<me->query("max_gin")/2)
	 return notify_fail("��ľ�Ѫ̫���ˣ��޷����������\n");
	if(me->query("kee")<me->query("max_kee")/2)
	 return notify_fail("�����Ѫ̫���ˣ��޷����������\n");
	if(me->query("sen")<me->query("max_sen")/2)
	 return notify_fail("��ľ���̫���ˣ��޷����������\n");
	 	
	message_vision("$N��"+environment(me)->query("short")+"��С��¯����"+metirial->name()+"���˽�ȥ��\n",me);
        message_vision(RED"\n$N"+RED+"�������䣬�𡰺�����һ������������\n"NOR,me);
        me->start_busy(5);
         call_out("do_msg",5,me,metirial,mweapon,met,wp,type,lev,0);
   	
        return 1;
}

void do_msg(object me,object metirial,mapping mweapon,string met,string wp,
            string type,int lev,int times)
{
	          
      if(!me||!metirial||environment(metirial)!=me)
        return;
      
      if(times>=sizeof(dazao_msg)){
      	call_out("do_msg2",5,me,metirial,mweapon,met,wp,type,lev);
      	me->start_busy(5);
      	return;
      }
      message_vision(dazao_msg[times]+"\n",me);
      
     if(lev>=1000)
      	call_out("do_msg",5,me,metirial,mweapon,met,wp,type,lev,times+1);
      else
      	call_out("do_msg",5,me,metirial,mweapon,met,wp,type,lev,times+3);
      me->start_busy(5);
      return;
}

void do_msg2(object me,object metirial,mapping mweapon,string met,string wp,
            string type,int lev)
{
   object weapon;
   int min_damage,max_damage,max_strong;
   int dodge=0,parry=0,enhance_min_damage=0,enhance_max_damage=0,double_damage=0;
   int intl=0,con=0,dex=0,str=0,kar=0,per=0,super=0;
   int no_need_force=0,no_need_maxforce=0,no_need_sx=0;
   int reduce_force=0,reduce_maxforce=0,reduce_sx=0;
   string longs;
   int score=0;
   int flag=0;
   
   if(!me||!metirial||environment(metirial)!=me)
        return;
   
   message_vision(RED"\n$N"+RED+"�������Я����ذ�ף����Լ��첲����ȥ��\n"NOR,me);
   tell_object(environment(me),WHT"\nֻ�����̡���һ������Ѫ�ɽ���ȥ��һ�����ð�˳�����\n\n"NOR);
   
   if(me->query("vocation_fenzhi")=="weapon"){//����Ǳ�����֧����������Ҫ�õöࡣ
     
     min_damage=lev/7+random(lev/10)+random(mweapon["damage"]);
     max_damage=min_damage+random(lev/3+random(mweapon["damage"])-min_damage);
     max_strong=lev*mweapon["strong"]/50;
     
     score=max_damage/10+min_damage/10;
     
     if(lev>=200){
     	if(random(100)>80){
          dodge=random(lev/10);
     	  score+=1;
     	}
        if(random(100)>90){
          parry=random(lev/10);
     	  score+=1;
     	}
     	if(random(100)>98){
     	  enhance_min_damage=random(lev/20);
     	  score+=2;
     	}
     	if(random(100)>98){
     	  enhance_max_damage=random(lev/20);
     	  score+=2;
     	}
     	if(random(120)>118){
     	  double_damage=random(lev/20);
     	  score+=2;
     	}
     	if(random(300)==me->query_kar()){
     	  intl=random(lev/60);
     	  score+=1;
     	}
     	if(random(300)==me->query_kar()){
     	  con=random(lev/60);
     	  score+=1;
     	}
     	if(random(300)==me->query_kar()){
     	  dex=random(lev/60);
     	  score+=1;
     	}
     	if(random(300)==me->query_kar()){
     	  str=random(lev/60);
     	  score+=1;
     	}
     	if(random(400)==me->query_kar()){
     	  kar=random(lev/60);
     	  score+=1;
     	}
     	if(random(400)==me->query_kar())
     	  per=random(lev/60);
     	if(random(300)==me->query_kar()){
     	  super=random(lev/100);
     	  if(super>9) super=9;
     	  score+=2;
     	}
     	if(random(100)==me->query_kar()){
     	  no_need_force=1;
     	  score+=1;
     	}
     	if(random(100)==me->query_kar()){
     	  no_need_maxforce=1;
     	  score+=1;
     	}
     	if(random(400)==me->query_kar()){
     	  no_need_sx=1;
     	  score+=1;
     	}
     	if(random(100)>90){
     	  reduce_force=lev/2+random(lev);
     	  score+=1;
     	}
     	if(random(100)>96){
     	  reduce_maxforce=lev/2+random(lev);
     	  score+=1;
     	}
     	if(random(100)>95){
     	  reduce_sx=random(lev/60);
     	  score+=1;
     	}
    } 	  
     	
   }
   else{
     min_damage=random(lev/20)+random(lev/20);
     max_damage=min_damage+random(min_damage);
     max_strong=lev*mweapon["strong"]/400;
     
     score=max_damage/10+min_damage/10;
     
   }
   
   if(me->query("dazao_poison")){
    min_damage-=min_damage/3;
    max_damage-=max_damage/3;
    max_strong-=max_strong/3;
   }
   
	weapon=new("/obj/weaponclass/"+type);
	wp=replace_string(wp,"$HIR$",""HIR"");
	wp=replace_string(wp,"$HIG$",""HIG"");
	wp=replace_string(wp,"$HIY$",""HIY"");
	wp=replace_string(wp,"$HIW$",""HIW"");
	wp=replace_string(wp,"$HIB$",""HIB"");
	wp=replace_string(wp,"$HIM$",""HIM"");
	wp=replace_string(wp,"$HIC$",""HIC"");
	wp=replace_string(wp,"$GRN$",""GRN"");
	wp=replace_string(wp,"$RED$",""RED"");
	wp=replace_string(wp,"$BLK$",""BLK"");
	wp=replace_string(wp,"$YEL$",""YEL"");
	wp=replace_string(wp,"$BLU$",""BLU"");
	wp=replace_string(wp,"$MAG$",""MAG"");
	wp=replace_string(wp,"$CYN$",""CYN"");
	wp=replace_string(wp,"$WHT$",""WHT"");
        wp=replace_string(wp,"$NOR$",""NOR"");
	wp=wp+NOR;
	weapon->set("name",wp);
	
	if(super>0){
	  weapon->set("super",super);
	 
	}		
	
	  switch(random(4)){
	   case 0: 
	           weapon->set("wield_str",score-score/5);
	           break;
	   case 1: 
	           weapon->set("wield_con",score-score/5);
	           break;	  	  
	   case 2: 
	           weapon->set("wield_dex",score-score/5);
	           break;
	   case 3: 
	           weapon->set("wield_int",score-score/5);
	           break;
	  }
	  
	           weapon->set("wield_force",score*16);	           
	   
	           weapon->set("wield_maxforce",score*90);	           	          
	
	longs="����"+me->name()+"��"+metirial->name()+"����ġ�"+wp+"��\n";
	
	weapon->set("long",longs);
	
	if(me->query("vocation_fenzhi")=="poison"){
	  weapon->set("poison_flag",1);	  
	}
	else
	weapon->set("poison_flag",0);
	
        weapon->set("weapon_prop/damage",max_damage);
        weapon->set("weapon_prop/min_damage",min_damage);
        
        weapon->set("weapon_prop/dodge",dodge);
        weapon->set("weapon_prop/armor",parry);
        weapon->set("weapon_prop/enhance_min_damage",enhance_min_damage);
        weapon->set("weapon_prop/enhance_max_damage",enhance_max_damage);
        weapon->set("weapon_prop/double_damage",double_damage);
        
        weapon->set("weapon_prop/strength",str);
        weapon->set("weapon_prop/intelligence",intl);
        weapon->set("weapon_prop/constitution",con);
        weapon->set("weapon_prop/dodgeaction",dex);
        
        weapon->set("weapon_prop/personality",per);
        weapon->set("weapon_prop/karma",kar);
        
        weapon->set("no_need_force",no_need_force);
        weapon->set("no_need_maxforce",no_need_maxforce);
        weapon->set("no_need_sx",no_need_sx);
        
        weapon->set("reduce_force",reduce_force);
        weapon->set("reduce_maxforce",reduce_maxforce);
        weapon->set("reduce_sx",reduce_sx);
        
        weapon->set("max_strong",max_strong);
	    weapon->set("metirial",metirial->name());
	    weapon->set("strong",max_strong);
	    weapon->set("flag",0);
	    
	    weapon->set("save_flag",1);
	    
	    weapon->setup();
	
	tell_object(environment(me),"\n"+weapon->name()+"������ˣ�\n");
	if(metirial->query_amount()&&
	metirial->query_amount()>1)
	 metirial->set_amount(metirial->query_amount()-1);
	else
        destruct(metirial);
        
	if(!weapon->move(me)){
	  tell_object(me,"��ĸ��ز����ˣ�\n");
	  weapon->move(environment(me));
	}
	
	me->receive_damage("kee",me->query("max_kee")/2);
	me->receive_damage("gin",me->query("max_gin")/2);
	me->receive_damage("sen",me->query("max_sen")/2);
	me->add("vocation_score",(min_damage+max_strong)/2);
	if(me->query_skill("duanzao-jishu",1)>=100)
        me->improve_skill("duanzao-jishu",(me->query_int())+me->query("max_pot"));
	else me->improve_skill("duanzao-jishu",random(10));
	
	me->set("dazao_busy",time());
	
	me->delete_temp("duanzao_skills");
   return;
}

int change_wield_msg(object me,string name,string msg,int flag)
{
   object weapon;
   
   if(!objectp(weapon=present(name,me)))
   return notify_fail("������û�����������\n");
   if(!weapon->query("skill_type"))
   return notify_fail("��ֻ���޸ı�����װ��������\n");
   
   if(weapon->query("rumor")||
      weapon->query("no_save")||
      weapon->query("super")
     )
     return notify_fail("����������ܱ��棬���Ǳ��޸�װ�������˰ɣ�\n");
   msg+="\n";
   if(strsrch(msg," ")!=-1)
   return notify_fail("�����в��ܴ��ո�\n");
   
        msg=replace_string(msg,"$HIR$",""HIR"");
	msg=replace_string(msg,"$HIG$",""HIG"");
	msg=replace_string(msg,"$HIY$",""HIY"");
	msg=replace_string(msg,"$HIW$",""HIW"");
	msg=replace_string(msg,"$HIB$",""HIB"");
	msg=replace_string(msg,"$HIM$",""HIM"");
	msg=replace_string(msg,"$HIC$",""HIC"");
	msg=replace_string(msg,"$GRN$",""GRN"");
	msg=replace_string(msg,"$RED$",""RED"");
	msg=replace_string(msg,"$BLK$",""BLK"");
	msg=replace_string(msg,"$YEL$",""YEL"");
	msg=replace_string(msg,"$BLU$",""BLU"");
	msg=replace_string(msg,"$MAG$",""MAG"");
	msg=replace_string(msg,"$CYN$",""CYN"");
	msg=replace_string(msg,"$WHT$",""WHT"");
        msg=replace_string(msg,"$NOR$",""NOR"");
	msg=msg+NOR;
	
   if(flag==WIELD){
     weapon->set("wield_msg",msg);
     tell_object(me,"װ����������Ϊ��\n");
     message_vision(msg,me,weapon);   
   }else{
     weapon->set("unwield_msg",msg);
     tell_object(me,"ж����������Ϊ��\n");
     message_vision(msg,me,weapon);
   }
   return 1;
}
   

int help(object me)
{
	write(@HELP
ָ���ʽ : dazao ԭ������ �������� �������� �˺��� ��̶�
           ��������֧����ɫ�ַ���
           dazao -wm ���� ����  ���޸� wield ����ʱ������
           dazao -uwm ���� ���� ���޸� unwield ����ʱ��������
                      ���ָ�ʽ�� $N���Լ�  $n������
                    �磺$N��ৡ���һ�����һ��$n�������С�
                    ����֧����ɫ���м䲻���пո�

������Ϊ������ר����������������������
���Դ��������Ϊ��
             ���ࣺsword
             ���ࣺblade
             ���ࣺstaff
             ���ࣺhammer
             ���ࣺwhip
             ���ࣺaxe
             ���ࣺfork
             ǹ�ࣺspear             
             ذ���ࣺdagger
             ���ࣺdagger_poison ����ذ�׿���ɢ��Ҳ���Դ̼�
                                 ����������Ǳ�ܡ�
HELP
    );
    return 1;
}
