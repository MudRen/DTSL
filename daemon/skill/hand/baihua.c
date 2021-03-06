//百花。
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -100

int perform(object me,object target)
{ 
   object weapon;
   int damage;
   string msg;
   
   weapon=me->query_temp("weapon");
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   
   if(!me->is_fighting())
   return notify_fail("「百花」只能在战斗中使用!\n");
   if(weapon)
    return notify_fail("拿着武器，如何使用「百花」？\n");
    if(!me->query_skill("baihua-zhang",1))
    return notify_fail("不学「百花掌」如何使用「百花」？\n");
    if((int)me->query("max_force")<700)
    return notify_fail("你的内力修为太低了!\n");
    if((int)me->query_skill("strike",1)<70)
    return notify_fail("你的基本掌法太差了！\n");
    if((int)me->query_skill("baihua-zhang",1)<70)
    return notify_fail("你的「百花掌」还不到家！\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「百花」！\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「百花」需要深厚的先天真气支持，你修为不够，如何能行？\n");
   
    damage=me->query("apply_points")/2;
    
    msg=HIC"$N"+HIC+"手掌平脱，宛如绽放的莲花，一股气劲猛地朝$n"+HIC+"撞去！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「百花」只能在战斗中使用!\n");
    
    msg=HIC"$N"+HIC+"紧跟着左掌一翻，从意想不到的角度朝$n"+HIC+"的$l处拍去！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「百花」只能在战斗中使用!\n");
    
    msg=YEL"$N"+YEL+"随后右掌跟上，瞬间幻化出梅花之形，分五路朝$n"+YEL+"的$l处拍去！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
  
    me->set_temp("perform_busy",time());
      
    return 1;   
  
}  
 
