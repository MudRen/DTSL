
#include <ansi.h>
inherit SSERVER;
/*�ķ�ִ�к���
  ͳһ���� /daemon/skill/exec/ �¡�
*/
int execute(object me,object victim)
{
  
  int time;
  string msg;
    
  if(victim!=me)
  return notify_fail("��ֻ�ܶ��Լ�ʹ������ķ���\n");
  if(me->query("vocation")!="ɱ��")
  return notify_fail("ֻ��ɱ����ʹ������ķ���\n");
  
  if(me->query_skill("wanshi-jue",1)<160)
  return notify_fail("�����ʯ����Ϊ������\n");
   
  if(me->query_temp("execute_wanshijue"))
  return notify_fail("������ʹ����ʯ����\n");
  if(time()-me->query_temp("execute_wanshijue_busy")<30)
  return notify_fail("���޷�����ʩչ��ʯ����\n");  
  if(me->query("force")<200)
  return notify_fail("����������㣡\n");
  
  me->add("force",-200);
    
  msg=HIB"$N"+HIB+"��ס�������������Ρ�\n"NOR;

  message_vision(msg,me);
  time=20*me->query_skill("wanshi-jue",1)/(me->query_skill("wanshi-jue",1)+150);
  if(time<=0)
  time=3;
 
  me->set_temp("execute_wanshijue",1);
  me->set_temp("killer_hide",1);
  me->set_temp("no_move","�����ڲ����޷��߶���\n");
  
  call_out("execute2",1,time,me);
  
  return 1;
}

void execute2(int time,object me)
{
   
   if(!me)
   return;
   time--;
 if(me->is_fighting()||time<=0){   
   message_vision("\n$N�ջ�����ʯ����\n",me);
   me->delete_temp("execute_wanshijue");
   me->set_temp("execute_wanshijue_busy",time());
   me->delete_temp("killer_hide");   
   me->delete_temp("no_move");
   return;
 }
 call_out("execute2",1,time,me);
}
