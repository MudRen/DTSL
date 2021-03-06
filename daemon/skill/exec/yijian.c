
#include <ansi.h>
inherit SSERVER;
/*心法执行函数
  统一放在 /daemon/skill/exec/ 下。
*/
int execute(object me,object victim)
{
  
  int time,flag=0;
  object weapon;
  string msg;
  
  weapon=me->query_temp("weapon");
  
  if(victim==me)
  return notify_fail("你不能对自己使用这个心法。\n");
  
  if(!weapon||weapon->query("skill_type")!="sword")
  return notify_fail("手中无剑，如何使用弈剑？\n");

  if(me->query_skill("yijian-shu",1)<190)
  return notify_fail("你的弈剑术修为不够！\n");
  
  if(!me->query("execute_quest/yijianshu"))
  return notify_fail("你现在无法施展此心法！\n");
  
  if(me->query_temp("execute_yijianshu"))
  return notify_fail("你正在使用弈剑术！\n");
  if(time()-me->query_temp("execute_yijianshu_busy")<20)
  return notify_fail("你无法连续施展弈剑术。\n");  
  if(me->query("force")<200)
  return notify_fail("你的内力不足！\n");
  
  me->add("force",-200);
    
  msg=HIG"$N"+HIG+"突然一挥手中的$w"+HIG+"，只见一道寒芒朝$n"+HIG+"的要穴刺去！\n"NOR;
  me->set_temp("action_msg",msg);
  flag=COMBAT_D->do_attack(me,victim,weapon,0,2);
  me->delete_temp("action_msg");
  
  if(!flag){
    me->set_temp("execute_yijianshu_busy",time()-10);
    return 1;
  }
  
  msg="\n$N要穴被刺，功力立刻降低了！\n";
  message_vision(msg,victim);
  time=20*me->query_skill("yijian-shu",1)/(me->query_skill("yijian-shu",1)+150);
  if(time<=0)
  time=3;
  victim->set_temp("no_action","你中了弈剑术，什么也做不了！\n");
  
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
    
   message_vision("\n$N收回了弈剑术。\n",me);
   me->delete_temp("execute_yijianshu");
   me->set_temp("execute_yijianshu_busy",time());
   
   return;
}
