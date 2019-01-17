//无相神功
//狮子吼。
#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	int damage,parry;
	string msg;
	
	if(target==me)
			return notify_fail("「狮子吼」只能用来攻击别人！\n");
	
	if(objectp(me->query_temp("city_war_guard")))
        return notify_fail("你正带兵打仗呢！\n");
	
	if(!living(target))
		return notify_fail("那不是个活物耶！\n");
	
	if(objectp(target->query_temp("city_war_guard")))
        return notify_fail("对方正带兵打仗呢！\n");
    
    if(target->is_city_war_guard()||target->query("no_roar"))
     return notify_fail("你不能向对方使用这种功夫！\n");
        
	if(environment(me)->query("no_fight"))
	return notify_fail("这里不能使用这么有威胁力的内功！\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("你不要吵醒别人了！\n");
	if(environment(me)->query("leitai"))
	return notify_fail("这里禁止使用这种功夫！\n");
	
	if(stringp(target->query("target_id"))
	   &&target->query("target_id")!=me->query("id"))
        return notify_fail(target->name()+"根本不理会你的战斗请求。\n");        
        if(arrayp(target->query("target_id"))
           &&member_array(me->query("id"),target->query("target_id"))==-1)
           return notify_fail(target->name()+"根本不理会你的战斗请求。\n");
        
        if(me->query("PKS")>=5)
        return notify_fail("你罪孽深重，无法使用此绝技了！");

	if(me->query("pker"))
	return notify_fail("通缉犯还是老实点吧！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(!me->query_skill("wuxiang-shengong",1))
		return notify_fail("不学无相神功如何使用「狮子吼」？\n");
	if((int)me->query_skill("wuxiang-shengong",1)<150)
		return notify_fail("你的无相神功修为不够！\n");
	if((int)me->query_skill("force",1)<150)
        return notify_fail("你的基本内功修为不够！\n");
	if(me->query("max_force")<1000)
		return notify_fail("你的内力修为不够！\n");
	if(me->query("force")<200)
		return notify_fail("你的内力不足以使用此内功！\n");
	if(time()-me->query_temp("exert_busy/roar")<10)
            return notify_fail("连续施展绝技需要深厚的先天真气支持，你修为不够，如何能行？\n");
	
	me->add("force",-200);
	damage=me->query_skill("force",1);
	parry=target->query_skill("force",1);
	
          msg=HIY"$N"+HIY+"双目突然射出两道光芒，朝$n"+HIY+"高诵一声佛号“阿弥陀佛”！\n"NOR;
	   
	if(random(damage+parry)>parry){
	   damage +=me->query_skill("wuxiang-shengong",1);
	   damage=damage*4;	   
	   target->receive_damage("sen",damage);
	   msg +="\n$n身上一颤，有些头昏目眩！\n\n";
            me->start_busy(1);
	}
	else
	msg +="\n$n连忙运气于耳，挡住了$N这一记「狮子吼」！\n\n";
            me->start_busy(1+random(2));
	message_vision(msg,me,target);
	
	if(!userp(target))
	 target->kill_ob(me);
	else
	 target->fight_ob(me);
	
	me->set_temp("exert_busy/roar",time());
	return 1;
}

