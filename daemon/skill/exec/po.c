
#include <ansi.h>
inherit SSERVER;
/*心法执行函数
  统一放在 /daemon/skill/exec/ 下。
*/
int execute(object me,object victim)
{
  
  string msg;
  
  if(victim!=me)
  return notify_fail("你不能对别人使用这个心法。\n");
  
  victim=offensive_target(me);
  
  if(me->query_skill("sashoufa",1))
  return notify_fail("你学了撒手法，无法施展「破」！\n");
  if(me->query_skill("siguanfa",1))
  return notify_fail("你学了死关法，无法施展「破」！\n");
  
  if(me->query_skill("wuwang-jing",1)<190)
  return notify_fail("你的无妄经修为不够！\n");
  if(me->query_temp("execute_wuwangjing"))
  return notify_fail("你正在使用无妄经！\n");
  if(time()-me->query_temp("execute_wuwangjing_busy")<15)
  return notify_fail("你无法连续施展心法。\n");  
  if(me->query("force")<200)
  return notify_fail("你的内力不足！\n");
  
  me->add("force",-200);
   
  msg=HIY"\n$N"+HIY+"默念无妄经，突然之间周身泛起金色的光芒！\n"NOR;
  
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
    
   message_vision("\n$N收回了无妄经神功。\n",me);
   
   me->delete_temp("execute_wuwangjing");
   me->delete_temp("no_eff_perform");
   me->set_temp("execute_wuwangjing_busy",time());
   
   return;
}
