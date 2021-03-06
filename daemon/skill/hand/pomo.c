//如来神掌
//佛光破魔
//by rzy 02.9.20

#include <ansi.h>
inherit SSERVER;

void check(object me);
void remove_effect(object me);

int perform(object me,object victim)
{
        int skill;
        int base_skill,sword_skill;
        
        skill = me->query_skill("wuxiang-shengong",1);
        
        if(skill>200) skill=200;
        
        base_skill= me->query_skill("strike",1);
        sword_skill= me->query_skill("rulai-shenzhang",1);
        
        if(me->query("PKS")>=5)
        return notify_fail("你罪孽深重，无法使用此绝技了！");
                       
        if(me->query("apply_points")<=0)
        	return notify_fail("凭你目前的气势无法施展「佛光破魔」！\n");
        if(me->query("max_force")<1000)
        	return notify_fail("你的内力修为太低了！\n");              
        if(me->query_skill("wuxiang-shengong",1)<110)  
        	return notify_fail("你的无相神功修为不够！\n");
        if(me->query_skill("strike",1)<110)
        	return notify_fail("你的基本掌法未够纯熟！\n");
        if(me->query_skill("rulai-shenzhang",1)<110)
        	return notify_fail("你的如来神掌不够纯熟！\n");
	if(me->query_temp("actionp_hit/pomo")) {
		remove_effect(me);
		return 1;
	}
                          
        if(time()-(int)me->query_temp("perform_busy")<6)
                return notify_fail("你刚刚施展过「佛光破魔」，内息还未平复。\n");  
        
        message_vision(HIG"$N"+HIG+"暗运真气，面上神光一闪即逝，神态中却隐隐透出一股自信。\n" NOR, me);
        me->set_temp("actionp_hit/pomo", 1);
        me->set_temp("pomo_time",skill/4);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
	object weapon;
	if(!me)
		return;
       
	weapon=me->query_temp("weapon");
	if(weapon) 
		remove_effect(me);
	else if(me->query_temp("pomo_time")<=0)
		remove_effect(me);                 
	else {
		me->add_temp("pomo_time",-1);
		call_out("check", 1, me);
	}
                     
}


void remove_effect(object me)
{
        if(!me) return;
        if(!me->query_temp("actionp_hit/pomo"))
        return;
        me->delete_temp("actionp_hit/pomo");
        me->set_temp("perform_busy",time());
        tell_object(me, HIG"\n你缓缓的收回了真气。\n\n"NOR);
        return;
}