//����������

#include <ansi.h>

inherit SSERVER;


int perform(object me,object target)
{ 
    object weapon,*ob,team_ob=0;
    string msg;
    int parry,flag,i;
    
    flag=0;
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("������������ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("�����޽������ʹ�á�������������\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("dijian-jue"))
    return notify_fail("��ѧ���ؽ��������ʹ�á�������������\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("sword",1)<110)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("dijian-jue",1)<110)
    return notify_fail("��ġ��ؽ������������ң�\n");
    if((int)me->query_skill("tiangang-sanjue",1)<100)
    return notify_fail("��ġ�����������������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ��������������\n");
    
    if(me->query("perform_quest/ditian")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ��������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/ditian")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ��������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    if(me->query_temp("perform_action/ditian"))
    return notify_fail("������ʹ�á�������������\n");
    
    parry=me->query("apply_points");
    
    if(!me->query("perform_quest/ditian")){
     flag=0;
     parry=parry/2;
    } else flag=1;   
    
    if(!flag){
    	msg=WHT"\n���ˡ�����������ٲ�����$N"+WHT+"�������"+weapon->name()+WHT+"���������ʣ������أ�$n"+WHT+"\n"+
    	   "�Ĺ��ƣ��缤����ӿ���У���$N"+WHT+"ȫƾһ������������������ס��������������һ��ʯ��\n"+
    	   "��Ҳ������\n"NOR;
    	message_vision(msg,me,target);
    	me->set_temp("apply/parry",parry);
    }
    else{
      ob=me->query_team();
      if(!arrayp(ob)){
      	msg=WHT"\n���ˡ�����������ٲ�����$N"+WHT+"�������"+weapon->name()+WHT+"���������ʣ������أ�$n"+WHT+"\n"+
    	   "�Ĺ��ƣ��缤����ӿ���У���$N"+WHT+"ȫƾһ������������������ס��������������һ��ʯ��\n"+
    	   "��Ҳ������\n"NOR;
    	me->set_temp("apply/parry",parry);
      }
      else{
        i=sizeof(ob);
        while(i--)
        if(ob[i])
        ob[i]->set_temp("apply/parry",parry);
        team_ob=ob[random(sizeof(ob))];
        msg=WHT"ֻ��һ������֮������$N"+WHT+"��"+weapon->name()+WHT+"���������������㷱���ķ���ɢ������\n"+
            "����֯����һ�����������Լ���Χ����Χס����ʱ��$n"+WHT+"���޴�����֮�У�\n"NOR;
      }
      message_vision(msg,me,target);
   }      
   
   me->set_temp("perform_action/ditian",1);
   if(!flag)
   call_out("clear_defence",5,me,ob,flag);
   else
   call_out("clear_defence",10,me,ob,flag);
    
    msg=HIC"$N"+HIC+"��$w"+HIC+"����$n"+HIC+"����һ��������������������ȴ�ֺ�δ������ҡ���������й���ȫ����ס��\n"+
        "��������$n"+HIC+"�������𵴣�$w"+HIC+"�����˲��˰�Ķ�����ÿ����һ�Σ�$w"+HIC+"��ֱ��һ�֣�\n"+
        "��$n"+HIC+"�����ظվ��𲽻�ȥ��\n"NOR;
    if(!userp(target))
    me->add_temp("apply/damage",parry);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    if(target&&!userp(target))
    me->add_temp("apply/damage",-parry);
    me->delete_temp("action_msg");
  
    if(!me->is_fighting())
    return notify_fail("������������ֻ����ս����ʹ��!\n");
    
    msg=YEL"$N"+YEL+"��$n"+YEL+"���Խ��֣�$n"+YEL+"�������Ͼ�������ţ�뺣�������ŵ״���$N"+YEL+"�Ĺ��������ﳤ�գ�\n"+
        "��Զ��֪����������$w"+YEL+"��ͻȻ����һ�ɵĴ����������������쾢��ֱ��$n"+YEL+"��\n"NOR;
    if(!userp(target))
    me->add_temp("apply/damage",parry);
    me->set_temp("action_msg",msg);
    flag=COMBAT_D->do_attack(me,target,weapon,0,2);
    if(target&&!userp(target))
    me->add_temp("apply/damage",-parry);
    me->delete_temp("action_msg");
   
   me->set_temp("perform_busy",time());
    return 1;   
  
}  

void clear_defence(object me,object *ob,int parry,int flag)
{
   string msg;
   int i;  
   
   if(!flag){
     if(!me) return;
     me->set_temp("apply/parry",0);
     
   }
   else{
     if(arrayp(ob)){
     	i=sizeof(ob);
     	while(i--)
     	 if(ob[i])
     	  ob[i]->set_temp("apply/parry",0);
     }
     else{
      if(!me) return;
      me->set_temp("apply/parry",0);
     }
  }
  msg="\n$N�ջ��˵ؽ����ķ���֮�ƣ�\n";
  if(me){
   me->delete_temp("perform_action/ditian");
   message_vision(msg,me);
  }
  return;
}
