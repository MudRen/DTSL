//烟雨朦胧
//因为有兵器的附加伤害，所以这里的
//伤害应该低一些。

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -200


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
   return notify_fail("「烟雨朦胧」只能在战斗中使用！\n");
   if(!weapon)
    return notify_fail("不拿武器，如何使用「烟雨朦胧」？\n");
   if(weapon->query("skill_type")!="whip")
    return notify_fail("不拿鞭子，如何使用「烟雨朦胧」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("shuiyun-xiufa",1))
    return notify_fail("不学「水云袖法」如何使用「烟雨朦胧」？\n");
    if(me->query("apply_points")<=0)
    return notify_fail("你的气势不足，无法使用「烟雨朦胧」！\n");
    
    if((int)me->query("max_force")<1500)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("whip",1)<160)
    return notify_fail("你的基本鞭法太差了！\n");
    if((int)me->query_skill("shuiyun-xiufa",1)<160)
    return notify_fail("你的「水云袖法」还不到家！\n");
    if((int)me->query_skill("bihai-force",1)<150)
    return notify_fail("你的「碧海神功」还不到家！\n");
    
    if(me->query("perform_quest/yanyu")
       &&time()-me->query_temp("perform_busy")<8)
       return notify_fail("连续施展「烟雨朦胧」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    if(!me->query("perform_quest/yanyu")
       &&time()-me->query_temp("perform_busy")<4)
       return notify_fail("连续施展「烟雨朦胧」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/yanyu"))
    damage=damage/2;
    else damage=damage*2;
  
    msg=WHT"$N"+WHT+"一伸一缩，$w"+WHT+"暴长，如团团花絮柔软拂动，妙若行云流水，令人看得心旷神怡，$w"+WHT+"中\n"+
        "似乎还充满诱人的清香，只听唰的一声，$w"+WHT+"击向$n"+WHT+"的$l！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
   
    if(!me->is_fighting())
    return notify_fail("「烟雨朦胧」只能在战斗中使用！\n");
    
    msg=HIC"$N"+HIC+"水云袖法既出，$w"+HIC+"连挥，攻势绵绵不绝如同波浪涟漪，突然脸上似笑非笑，出招渐渐软\n"+
        "弱起来，把流云般的$w"+HIC+"使得慵懒无力，令$n"+HIC+"诧异万分。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
   if(!me->is_fighting())
    return notify_fail("「烟雨朦胧」只能在战斗中使用！\n");
    
    msg=HIG"$N"+HIG+"手中的$w"+HIG+"劲力突然变化，忽抛忽拂，形状像车轮，倏地变为托塔，奇幻无比，$w"+HIG+"上风\n"+
        "声劲急震耳，$n"+HIG+"一听而知，纵是铜墙铁壁，若是被$w"+HIG+"拂中，也得损毁一大块。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(objectp(target)&&random(10)>6){
    	msg=WHT"\n$N"+WHT+"在恍惚之中似乎迷乱了神智，动作已然混乱！\n\n"NOR;
    	message_vision(msg,target);
    	target->start_busy(random(5));
    }
    
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
