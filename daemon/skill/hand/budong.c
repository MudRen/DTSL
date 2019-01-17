//不动根本印。
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int i;
     object weapon;
     
     if(target&&target!=me)
     return notify_fail("你只能对自己使用「不动根本印」。\n");
     
     weapon=me->query_temp("weapon");	
     if(weapon)
     return notify_fail("拿着武器，如何使用「不动根本印」？\n");
     if(me->query_temp("perform_jzzy"))
    return notify_fail("你正在使用九字真言。\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("不学「九字真言」如何使用「不动根本印」？\n");
    if((int)me->query("max_force")<2000)
    return notify_fail("你的内力修为太低了!\n");
    if((int)me->query("force")<200)
    return notify_fail("你的内力不够使用此招数!\n");
    if((int)me->query_skill("jiuzi-zhenyan",1)<120)
    return notify_fail("你的九字真言太差了！\n");
    if((int)me->query_skill("strike",1)<120)
    return notify_fail("你的基本掌法还不到家！\n");
    
    if(time()-me->query_temp("perform_busy")<5)
    return notify_fail("你真气不足，无法施展「不动根本印」！\n");
    
    message_vision(HIC"$N"+HIC+"暗施“不动根本印”只见在月色洒照下，脸容不\n"+
                   "见半点情绪表情的波动，仿如入静的高僧，宝相庄严，\n"+
                   "但自有一种说不出的风流潇洒，合而形成奇特的魅力，\n"+
                   "极具震慑人心的气度。\n"NOR,me);
    i=me->query_skill("jiuzi-zhenyan",1)/2;
    me->add_temp("apply/armor",i);
    me->set_temp("perform_jzzy",1);
    me->add("force",-200);
    
    call_out("rid_defence",i/7,me,i);
    return 1;   
  
}  
 
void rid_defence(object me,int i)
{
  if(!me) return;
  message_vision("\n$N长吁了口气，气色如常。\n",me);
  me->add_temp("apply/armor",-i);
  me->delete_temp("perform_jzzy");
  me->set_temp("perform_busy",time());
  return;
}