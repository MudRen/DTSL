//渡劫指
//六道轮回。

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage,flag=0;
   
    weapon=me->query_temp("weapon");
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
   return notify_fail("「六道轮回」只能在战斗中使用!\n");
   if(weapon)
    return notify_fail("拿着武器，如何使用「六道轮回」？\n");
    if(me->query("PKS")>=5)
        return notify_fail("你罪孽深重，无法使用此绝技了！");
    if(!me->query_skill("dujie-zhi",1))
    return notify_fail("不学「渡劫指」如何使用「六道轮回」？\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("你的内力修为太低了!\n");
    if((int)me->query_skill("finger",1)<110)
    return notify_fail("你的基本指法太差了！\n");
    if((int)me->query_skill("dujie-zhi",1)<110)
    return notify_fail("你的「渡劫指」还不到家！\n");
    if((int)me->query_skill("wuxiang-shengong",1)<100)
    return notify_fail("你的「无相神功」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「六道轮回」！\n");
    if(me->query("perform_quest/liudao")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("连续施展「六道轮回」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/liudao")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「六道轮回」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/liudao"))
    damage=damage/2;
    me->set("apply_points",0);
    
    msg=HIY"$N"+HIY+"手指不断变化，使$n"+HIY+"生出幻觉，宛如身在「天道」之中，不由地沉溺于其中的欢乐之\n"+
        "中，但却隐约感觉到即将到来的地狱之感！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「六道轮回」只能在战斗中使用!\n");
   /* 
    if(flag<=0){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    flag=0;
    */
    msg=HIR"$N"+HIR+"手指继续变换，$n"+HIR+"眼前幻象从生，浑然堕入阿修罗道。心中的种种嫉妒之心顿时高涨，\n"+
        "使得自己的神智模糊不清！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「六道轮回」只能在战斗中使用!\n");
    /* 
    if(flag<=0){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    flag=0;
    */
    msg=HIC"$N"+HIC+"手指继续变换，$n"+HIC+"眼前幻象从生，浑然堕入人道，生、老、病、\n"+
        "死的痛苦，以及与所爱的人别离，与所怨憎的人相遇，挫折和不满足等苦恼一齐涌上\n"+
        "头来，不由得心力交瘁！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「六道轮回」只能在战斗中使用!\n");
    
    
    if(!me->query("perform_quest/liudao")){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    call_out("perform2",3,me,target,damage);
    me->set_temp("perform_busy",time());
    return 1;   
  
}  

int perform2(object me,object target,int damage)
{
    string msg;
    int flag=0;
    
    if(!me||!target)
    return 1;
    if(!me->is_fighting(target))
    return 1;
    
    if(me->query_temp("weapon"))
    return 1;
    
    if(me->is_busy())
    return 1;
    
    msg=HIB"$N"+HIB+"手指继续变换，$n"+HIB+"眼前幻象从生，浑然堕入畜生道。自己的思维\n"+
        "顿时模糊起来，生出遭受着极度饿渴的痛苦的感觉！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「六道轮回」只能在战斗中使用!\n");
    /* 
    if(flag<=0){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    flag=0;
    */
    msg=BLU"$N"+BLU+"手指继续变换，$n"+BLU+"眼前幻象从生，浑然堕入饿鬼道。顿时觉得好象\n"+
        "飘荡的饿鬼忍受着极度饥渴的苦恼，永远遭受着无法满足的极度欲望折磨。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「六道轮回」只能在战斗中使用!\n");
    /* 
    if(flag<=0){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    flag=0;
    */
    msg=RED"$N"+RED+"手指继续变换，$n"+RED+"眼前幻象从生，浑然堕入地狱道。顿时浑身感到\n"+
        "被千百个刺枪插入身体，身体与燃烧的热火已经无法区分！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    me->set_temp("perform_busy",time());
    return 1;
}
