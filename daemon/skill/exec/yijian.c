
#include <ansi.h>
inherit SSERVER;
/*�ķ�ִ�к���
  ͳһ���� /daemon/skill/exec/ �¡�
*/
int execute(object me,object victim)
{
  
  int time,flag=0;
  object weapon;
  string msg;
  
  weapon=me->query_temp("weapon");
  
  if(victim==me)
  return notify_fail("�㲻�ܶ��Լ�ʹ������ķ���\n");
  
  if(!weapon||weapon->query("skill_type")!="sword")
  return notify_fail("�����޽������ʹ���Ľ���\n");

  if(me->query_skill("yijian-shu",1)<190)
  return notify_fail("����Ľ�����Ϊ������\n");
  
  if(!me->query("execute_quest/yijianshu"))
  return notify_fail("�������޷�ʩչ���ķ���\n");
  
  if(me->query_temp("execute_yijianshu"))
  return notify_fail("������ʹ���Ľ�����\n");
  if(time()-me->query_temp("execute_yijianshu_busy")<20)
  return notify_fail("���޷�����ʩչ�Ľ�����\n");  
  if(me->query("force")<200)
  return notify_fail("����������㣡\n");
  
  me->add("force",-200);
    
  msg=HIG"$N"+HIG+"ͻȻһ�����е�$w"+HIG+"��ֻ��һ����â��$n"+HIG+"��ҪѨ��ȥ��\n"NOR;
  me->set_temp("action_msg",msg);
  flag=COMBAT_D->do_attack(me,victim,weapon,0,2);
  me->delete_temp("action_msg");
  
  if(!flag){
    me->set_temp("execute_yijianshu_busy",time()-10);
    return 1;
  }
  
  msg="\n$NҪѨ���̣��������̽����ˣ�\n";
  message_vision(msg,victim);
  time=20*me->query_skill("yijian-shu",1)/(me->query_skill("yijian-shu",1)+150);
  if(time<=0)
  time=3;
  victim->set_temp("no_action","�������Ľ�����ʲôҲ�����ˣ�\n");
  
  me->set_temp("execute_yijianshu",1);
  
  call_out("execute2",time,me,victim);
  
  return 1;
}

void execute2(object me,object victim)
{
   if(victim)
    victim->delete_temp("no_action");
   if(!me)
   return;
    
   message_vision("\n$N�ջ����Ľ�����\n",me);
   me->delete_temp("execute_yijianshu");
   me->set_temp("execute_yijianshu_busy",time());
   
   return;
}
