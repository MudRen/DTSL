
#include <ansi.h>
inherit SSERVER;
/*�ķ�ִ�к���
  ͳһ���� /daemon/skill/exec/ �¡�
*/
int execute(object me,object victim)
{
  
  string msg;
  
  if(victim!=me)
  return notify_fail("�㲻�ܶԱ���ʹ������ķ���\n");
  
  victim=offensive_target(me);
  
  if(me->query_skill("sashoufa",1))
  return notify_fail("��ѧ�����ַ����޷�ʩչ���ơ���\n");
  if(me->query_skill("siguanfa",1))
  return notify_fail("��ѧ�����ط����޷�ʩչ���ơ���\n");
  
  if(me->query_skill("wuwang-jing",1)<190)
  return notify_fail("�����������Ϊ������\n");
  if(me->query_temp("execute_wuwangjing"))
  return notify_fail("������ʹ����������\n");
  if(time()-me->query_temp("execute_wuwangjing_busy")<15)
  return notify_fail("���޷�����ʩչ�ķ���\n");  
  if(me->query("force")<200)
  return notify_fail("����������㣡\n");
  
  me->add("force",-200);
   
  msg=HIY"\n$N"+HIY+"Ĭ����������ͻȻ֮���������ɫ�Ĺ�â��\n"NOR;
  
     message_vision(msg,me);
 
  me->set_temp("execute_wuwangjing",1);
  me->set_temp("no_eff_perform",1);
  
  call_out("execute2",me->query_skill("wuwang-jing",1)/10,me);
  
  return 1;
}

void execute2(object me)
{
   if(!me)
    return;
    
   message_vision("\n$N�ջ����������񹦡�\n",me);
   
   me->delete_temp("execute_wuwangjing");
   me->delete_temp("no_eff_perform");
   me->set_temp("execute_wuwangjing_busy",time());
   
   return;
}
