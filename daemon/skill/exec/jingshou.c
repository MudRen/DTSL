
#include <ansi.h>
inherit SSERVER;
/*�ķ�ִ�к���
  ͳһ���� /daemon/skill/exec/ �¡�
*/
int execute(object me,object victim)
{
  
  int armor;
  string msg;
  
  if(victim!=me)
  return notify_fail("�㲻�ܶԱ���ʹ������ķ���\n");
  
  victim=offensive_target(me);
  
  if( me->query_skill("sashoufa",1)&&
      (me->query_skill("sashoufa",1)<190
      ||!me->query("execute_quest/xinyoulingxi"))
    )
  return notify_fail("������ַ��������ң��޷�ʩչ�����ء���\n");
  if(me->query_skill("siguanfa",1)&&
      (me->query_skill("siguanfa",1)<190
      ||!me->query("execute_quest/jianxintongming"))
    )
  return notify_fail("������ط��������ң��޷�ʩչ�����ء���\n");
  
  if(me->query_temp("execute_jingshou"))
  return notify_fail("������ʹ�á����ء���\n");
  if(time()-me->query_temp("execute_jingshou_busy")<15)
  return notify_fail("���޷�����ʩչ�����ء���\n");  
  if(me->query("force")<200)
  return notify_fail("����������㣡\n");
  
  me->add("force",-200);
  if(me->query_skill("siguanfa",1))
  armor=me->query_skill("siguanfa",1)*2;
  else
  armor=me->query_skill("sashoufa",1)*2;
   
  msg=HIY"\n$N"+HIY+"Ĭ��Ⱥ������ؾ������̴������ƣ������ƺ�������һ����ǽ��\n"NOR;
  
     message_vision(msg,me);
 
  me->set_temp("execute_jingshou",1);
  me->set_temp("no_eff_combat",1);
  me->add_temp("apply/armor",armor);
  
  call_out("execute2",armor/(2*8),me,armor);
  
  return 1;
}

void execute2(object me,int armor)
{
   if(!me)
    return;
    
   message_vision("\n$N�ջ��˴Ⱥ������񹦡�\n",me);
   
   me->delete_temp("execute_jingshou");
   me->delete_temp("no_eff_combat");
   me->add_temp("apply/armor",-armor);
   me->set_temp("execute_jingshou_busy",time());
   
   return;
}
