//纤手驭龙
//因为有兵器的附加伤害，所以这里的
//伤害应该低一些。

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 50

void show_msg(object me,object victim)
{
    string str;
    
     if (userp(victim)&&
          (victim->query("eff_kee")<0 || 
          !living(victim) 
          )
        )   {
          str="听说"+victim->name()+""HIM"死在"+me->name()+""HIM"的"HIR"纤手驭龙"HIM"之下，浑身鲜血淋漓！"NOR;
                        message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
     }
     return;
}

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
   return notify_fail("「纤手驭龙」只能在战斗中使用！\n");
   if(!weapon)
    return notify_fail("不拿武器，如何使用「纤手驭龙」？\n");
   if(weapon->query("skill_type")!="whip")
    return notify_fail("不拿鞭子，如何使用「纤手驭龙」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("tianmo-dai",1))
    return notify_fail("不学[天魔带]如何使用「纤手驭龙」？\n");
    if(me->query("apply_points")<=0)
    return notify_fail("你的气势不足，无法使用「纤手驭龙」！\n");
    
    if((int)me->query("max_force")<1500)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("whip",1)<160)
    return notify_fail("你的基本鞭法太差了！\n");
    if((int)me->query_skill("tianmo-dai",1)<160)
    return notify_fail("你的「天魔带」还不到家！\n");
    if((int)me->query_skill("tianmo-dafa",1)<150)
    return notify_fail("你的「天魔大法」还不到家！\n");
    
    if(time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「纤手驭龙」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/yulong"))
    damage=damage/2;//如果没解迷题。
    /*
    if(!me->query_temp("apply/yulong_cloth"))
    damage=damage-damage/3;//如果没穿指定的衣服。
    */

    msg=HIC"$N"+HIC+"突然拂向$n"+HIC+"使人叹为观止的一袖，在尚未触及$n"+HIC+"的两双手掌时，忽地化为漫空\n袖影，虚实难分。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「纤手驭龙」只能在战斗中使用！\n");
    
    
    msg=WHT"$N"+WHT+"$w忽地长了半丈，衣袖里飞出一条白丝带，先穿行于$n"+WHT+"两掌之间，再收紧时，\n已将$n"+WHT+"一对手缚在一起。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「纤手驭龙」只能在战斗中使用！\n");
    
    
    msg=HIG"$N"+HIG+"俏脸似嗔非嗔地横了$n"+HIG+"一眼，接着横移开去，拖得$n"+HIG+"踉跄急跌，全无反击之力。\n$N"+HIG+"以丝带遥控着$n"+HIG+"四处撞击。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「纤手驭龙」只能在战斗中使用！\n");
    
  
    msg=HIR"$N"+HIR+"一道接一道的天魔真劲，透过$w"+HIR+"攻往$n"+HIR+"，硬生生冲击得$n"+HIR+"一口口鲜血喷出来，\n"+
        "人又像傀儡般身不由己，横移直撞，全由$N"+HIR+"作主，情景凄厉至极，令人不忍卒睹。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set_temp("perform_busy",time());
    show_msg(me,target);
    return 1;   
  
}  
 
