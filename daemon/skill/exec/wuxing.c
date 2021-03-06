
#include <ansi.h>
inherit SSERVER;
/*心法执行函数
  统一放在 /daemon/skill/exec/ 下。
*/
int execute(object me,object victim)
{
  
  int time;
  string msg;
    
  if(victim!=me)
  return notify_fail("你只能对自己使用这个心法。\n");
  if(me->query("vocation")!="杀手")
  return notify_fail("只有杀手能使用这个心法。\n");
  
  if(me->query_skill("wanshi-jue",1)<160)
  return notify_fail("你的顽石诀修为不够！\n");
   
  if(me->query_temp("execute_wanshijue"))
  return notify_fail("你正在使用顽石诀！\n");
  if(time()-me->query_temp("execute_wanshijue_busy")<30)
  return notify_fail("你无法连续施展顽石诀。\n");  
  if(me->query("force")<200)
  return notify_fail("你的内力不足！\n");
  
  me->add("force",-200);
    
  msg=HIB"$N"+HIB+"屏住呼吸，藏起身形。\n"NOR;

  message_vision(msg,me);
  time=20*me->query_skill("wanshi-jue",1)/(me->query_skill("wanshi-jue",1)+150);
  if(time<=0)
  time=3;
 
  me->set_temp("execute_wanshijue",1);
  me->set_temp("killer_hide",1);
  me->set_temp("no_move","你正在藏身，无法走动。\n");
  
  call_out("execute2",1,time,me);
  
  return 1;
}

void execute2(int time,object me)
{
   
   if(!me)
   return;
   time--;
 if(me->is_fighting()||time<=0){   
   message_vision("\n$N收回了顽石诀。\n",me);
   me->delete_temp("execute_wanshijue");
   me->set_temp("execute_wanshijue_busy",time());
   me->delete_temp("killer_hide");   
   me->delete_temp("no_move");
   return;
 }
 call_out("execute2",1,time,me);
}
