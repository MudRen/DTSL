
#include <ansi.h>
inherit SSERVER;
/*�ķ�ִ�к���
  ͳһ���� /daemon/skill/exec/ �¡�
*/
int execute(object me,object victim)
{
  int time,flag=0;
  string msg;
  
  if(victim!=me)
  return notify_fail("�㲻�ܶԱ���ʹ������ķ���\n");
  
  victim=offensive_target(me);
  
  if(me->query_skill("huachan",1))
  return notify_fail("��ѧ�˻������޷�ʩչ����ӡ��\n");
  
  if(!me->query("execute_quest/busiyin_ok"))
  return notify_fail("�����ڻ��޷�ʩչ��ô�������书��\n");
  
  if(me->query_skill("busi-yin",1)<190)
  return notify_fail("��Ĳ���ӡ��Ϊ������\n");
  if(me->query_temp("execute_busiyin"))
  return notify_fail("������ʹ�ò���ӡ��\n");
  if(time()-me->query_temp("execute_busiyin_busy")<20)
  return notify_fail("���޷�����ʩչ����ӡ��\n"); 
  if(me->query("force")<200)
  return notify_fail("����������㣡\n");
  
  me->add("force",-200);

  msg=HIB"\n$N"+HIB+"����һ������"+HIY+"˫Ŀ������˵Ĺ�â��"+HIB+"����ʱ���������"+HIG+"����Ҳ������һ����ǽ��\n"NOR;
  
  if(victim){
     msg+="\n"+victim->name()+"�������У����ɵ��ܵ��˳������\n";
     message_vision(msg,me);
     flag+=COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),0,2);
     flag+=COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),0,2);
     flag+=COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),0,2);
     if(flag&&me->query_skill("busi-yin",1)>=200&&victim){
        victim->set_temp("bsy_skill_damage",me->query_skill("busi-yin",1));
        victim->set_temp("bsy_damage_time",time());
     }
  }
  else
  message_vision(msg,me);
  
  me->set_temp("execute_busiyin",1);
  
  time=15*(me->query_skill("busi-yin",1)+100)/me->query_skill("busi-yin",1);
  call_out("execute2",time,me);
  
  return 1;
}

void execute2(object me)
{
   int time;
   
   if(!me)
    return;
    
   tell_object(me,HIR"\n��Ĳ���ӡ���Ѿ��������壡\n"NOR);
   me->set_temp("back_damage",me->query_skill("busi-yin",1));
   me->set_temp("back_wound",me->query_skill("busi-yin",1));   
   time=20*me->query_skill("busi-yin",1)/(me->query_skill("busi-yin",1)+50);
   call_out("execute3",time,me);
   return;
}

void execute3(object me)
{
  
   if(!me)
    return;
    
   tell_object(me,HIR"\n���ջ��˲���ӡ����\n"NOR);
   me->delete_temp("back_damage");
   me->delete_temp("back_wound");
   me->delete_temp("execute_busiyin");
   me->set_temp("execute_busiyin_busy",time());
   
   return;
}
