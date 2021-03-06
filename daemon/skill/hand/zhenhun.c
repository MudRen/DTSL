//天罡拳
//天罡镇魂
//by rzy 02.9.17

#include <ansi.h>
inherit SSERVER;

int perform(object me,object target) {
	int i;
	object weapon;
	weapon=me->query_temp("weapon");  

	if(!target)
          if(!objectp(target=offensive_target(me)))
		return notify_fail("目前你没有攻击的目标！\n");
	if(!me->is_fighting())
		return notify_fail("只有在战斗时才可以使用「天罡镇魂」。\n");
	if(me->query("PKS")>=5)
        return notify_fail("你罪孽深重，无法使用此绝技了！");
	if(weapon)
		return notify_fail("拿着武器无法使用「天罡镇魂」！\n");
	if(me->query_temp("perform_zhenhun"))
		return notify_fail("你正在使用「天罡镇魂」！\n");
	if(!me->query_skill("tiangang-quan",1))
		return notify_fail("你还没有学会「天罡拳」！\n");
	if((int)me->query("max_force")<1000)
		return notify_fail("以你的内力修为无法使出「天罡镇魂」这样的招数！\n");
	if((int)me->query_skill("wuxiang-shengong",1)<110)
		return notify_fail("你的「无相神功」还不到家！\n");
	if((int)me->query_skill("tiangang-quan",1)<110)
		return notify_fail("你的「天罡拳」还不够娴熟！\n");
	if((int)me->query_skill("cuff",1)<110)
		return notify_fail("你的基本拳法还不到家！\n");
	if(me->query_skill("bikouchan",1)<100)
		return notify_fail("你的闭口禅修为太低了！\n");
	if(time()-me->query_temp("perform_busy")<5)
		return notify_fail("你刚刚使用过「天罡镇魂」，内息还未平复！\n");
	if(me->query("force")<500)
	 return notify_fail("你的内力不够！\n");
		
	message_vision(HIR"$N"+HIR+"口中传来一阵低声吟唱，转瞬间声大如雷。只见$N"+HIR+"浑身衣衫鼓胀，内力充盈全身，宝相庄严，\n"+
			"有如罗汉天降一般，正是「天罡镇魂诀」！\n"NOR,me,target);
		i=me->query_skill("tiangang-quan",1)*2/3+me->query("apply_points");
		me->add_temp("apply/damage",i);
		me->set_temp("perform_zhenhun",1);
		me->add("force",-500);
    
		call_out("rid_damag",me->query_skill("tiangang-quan",1)/5,me,i);
		return 1;   
}

void rid_damag(object me,int i) {
	if(!me)
		return;
	message_vision(HIR"\n$N"+HIR+"低吟了一声佛号，缓缓收回真气。\n"NOR,me);
	me->add_temp("apply/damage",-i);
	me->delete_temp("perform_zhenhun");
	me->set_temp("perform_busy",time());
	return;
}
