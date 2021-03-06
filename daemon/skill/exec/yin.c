
#include <ansi.h>
inherit SSERVER;
/*心法执行函数
  统一放在 /daemon/skill/exec/ 下。
*/
int execute(object me,object victim)
{
  int time,flag=0;
  string msg;
  
  if(victim!=me)
  return notify_fail("你不能对别人使用这个心法。\n");
  
  victim=offensive_target(me);
  
  if(me->query_skill("huachan",1))
  return notify_fail("你学了画禅，无法施展不死印！\n");
  
  if(!me->query("execute_quest/busiyin_ok"))
  return notify_fail("你现在还无法施展这么厉害的武功！\n");
  
  if(me->query_skill("busi-yin",1)<190)
  return notify_fail("你的不死印修为不够！\n");
  if(me->query_temp("execute_busiyin"))
  return notify_fail("你正在使用不死印！\n");
  if(time()-me->query_temp("execute_busiyin_busy")<20)
  return notify_fail("你无法连续施展不死印。\n"); 
  if(me->query("force")<200)
  return notify_fail("你的内力不足！\n");
  
  me->add("force",-200);

  msg=HIB"\n$N"+HIB+"深吸一口气，"+HIY+"双目射出摄人的光芒，"+HIB+"身法顿时灵活起来，"+HIG+"周身也产生了一道气墙！\n"NOR;
  
  if(victim){
     msg+="\n"+victim->name()+"身陷其中，不由得受到了冲击！！\n";
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
    
   tell_object(me,HIR"\n你的不死印功已经达至顶峰！\n"NOR);
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
    
   tell_object(me,HIR"\n你收回了不死印功！\n"NOR);
   me->delete_temp("back_damage");
   me->delete_temp("back_wound");
   me->delete_temp("execute_busiyin");
   me->set_temp("execute_busiyin_busy",time());
   
   return;
}
