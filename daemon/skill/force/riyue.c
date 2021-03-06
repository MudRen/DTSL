//炎阳大法
//日月交辉。
inherit SSERVER;

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	string msg;
	object guard;
	
	if(target!=me)
			return notify_fail("「日月交辉」不能用来攻击别人！\n");
	if(environment(me)->query("no_fight"))
	return notify_fail("这里不能使用这么有威胁力的内功！\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("你不要吵醒别人了！\n");
		
	if(me->query("pker"))
	return notify_fail("通缉犯还是老实点吧！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	
	if(!me->query_skill("yanyang-dafa",1))
		return notify_fail("不学炎阳大法如何使用「日月交辉」？\n");
	if((int)me->query_skill("yanyang-dafa",1)<160)
		return notify_fail("你的炎阳大法修为不够！\n");
	if((int)me->query_skill("force",1)<160)
        return notify_fail("你的基本内功修为不够！\n");
	if(me->query("force")<300)
		return notify_fail("你的内力不足以使用此内功！\n");
	if(me->query_temp("exert_yanyangdafa"))
	return notify_fail("你正在使用炎阳大法。\n");
	if(time()-me->query_temp("exert_busy/yanyangdafa")<15)
          return notify_fail("连续施展绝技需要深厚的先天真气支持，你修为不够，如何能行？\n");
		
	me->add("force",-300);
	
	msg=HIR"$N"+HIR+"聚气集身，身法顿时快了起来，宛如两个人一般！\n"NOR;
	message_vision(msg,me);
	me->set_temp("exert_yanyangdafa",1);
	
	guard=new(__DIR__"npc/guard");
	guard->move(environment(me));
	guard->set_leader(me);
	guard->set_status(me);
	me->add_temp_array("job_temp_killer",guard);
	target=offensive_target(me);
	if(objectp(target)){
	   if(me->is_killing(target->query("id"))){
	     guard->kill_ob(target);
	     target->kill_ob(guard);
	   }else{
	     guard->fight_ob(target);
	     target->fight_ob(guard);
	   }
	}
	
	call_out("exert2",me->query_skill("yanyang-dafa",1)/5,me,guard);
	
	return 1;
}

int exert2(object me,object guard)
{
   if(!me)
   return 1;
   if(guard)
   destruct(guard);
   
   message_vision("\n$N收回了炎阳大法。\n\n",me);
   
   me->set_temp("exert_busy/yanyangdafa",time());
   me->delete_temp("exert_yanyangdafa");
   return 1;
}
