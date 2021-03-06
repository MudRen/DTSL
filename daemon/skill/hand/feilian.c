//魔心连环:飞莲。
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
		return notify_fail("「飞莲」只能在战斗中使用!\n");
   if(weapon)
    return notify_fail("拿着武器，如何使用「飞莲」？\n");
    if(!me->query_skill("moxin-lianhuan"))
    return notify_fail("不学「魔心连环」如何使用「飞莲」？\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("strike",1)<110)
    return notify_fail("你的基本掌法太差了！\n");
    if((int)me->query_skill("moxin-lianhuan",1)<110)
    return notify_fail("你的「魔心连环」还不到家！\n");
    if((int)me->query_skill("tianmo-dafa",1)<100)
    return notify_fail("你的「天魔大法」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「飞莲」！\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「飞莲」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points")/2;
    
    msg=YEL"$N"+YEL+"左右两手从袖内探出，像一对追逐飞舞的银碟般，莲花般的手印，看似要硬挡，\n"+
    "其实用的却是卸移的精妙手法，务令$n"+YEL+"有力难施。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「飞莲」只能在战斗中使用!\n");
    
    msg=HIY"$N"+HIY+"一招莲花初现施出，脚踏奇步，双手合拢如莲，刹那间推出三朵莲劲，\n"+
    "分别袭向$n"+HIY+"左右肩井穴和面门，热气漫空！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「飞莲」只能在战斗中使用!\n");
    
    msg=HIR"$N"+HIR+"倏地移往$n"+HIR+"正面处，陀螺般旋转起来，拢手作莲花势，劲气爆空生响，震人耳\n"+
        "鼓，像朵朵盛开的无形莲花，往$n"+HIR+"印去，玄机暗含，摄人心魄，奇诡至极点！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
