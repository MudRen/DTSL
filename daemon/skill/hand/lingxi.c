//修罗指
//灵犀奇指
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage;
   
    weapon=me->query_temp("weapon");
    
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
	if(!me->is_fighting())
		return notify_fail("「灵犀奇指」只能在战斗中使用!\n");
   if(weapon)
    return notify_fail("拿着武器，如何使用「灵犀奇指」？\n");
    if(!me->query_skill("xiuluo-zhi",1))
    return notify_fail("不学「修罗指」如何使用「灵犀奇指」？\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("finger",1)<110)
    return notify_fail("你的基本指法太差了！\n");
    if((int)me->query_skill("xiuluo-zhi",1)<110)
    return notify_fail("你的「修罗指」还不到家！\n");
    if((int)me->query_skill("qingxin-force",1)<100)
    return notify_fail("你的「清心普善诀」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「灵犀奇指」！\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「灵犀奇指」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points")/2;
    
    msg=WHT"$N"+WHT+"轻抬玉手，笃地一声娇吟。瞬时，手指彷佛活起来了，水银泻地的往$n"+WHT+"突去，\n"+
        "一道道的真气、或直线、或弧线、或菱或角，带者惊人的杀伤力朝$n"+WHT+"攻去。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「灵犀奇指」只能在战斗中使用!\n");
    
    msg=HIY"$N"+HIY+"指劲如芒、指弹如雷、指气如风、指风如雾，$N"+HIY+"的指劲彷佛无所不在，狠狠打击$n"+HIY+"的\n"+
        "视、听、闻、味、触五觉。顿时$n"+HIY+"防守大受影响，眼看就要立毙指下！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「灵犀奇指」只能在战斗中使用!\n");
    
    msg=HIG"$N"+HIG+"的玉指变成带有异力的神器，没有时间的限制，破过去而来、立现在而至、乘未来\n"+
        "而去。没有空间的问题，顺手而挥、随手而扫、提手而刺！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
