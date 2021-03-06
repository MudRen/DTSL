//九转剑决
//流星幻舞
//by rzy 02.09.23

#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
	int i;
	int last_time;
	object weapon;
	weapon=me->query_temp("weapon");
	
	if(!me->is_fighting(target))
		return notify_fail("「流星幻舞」要在战斗中施展！\n");
	if(!weapon || weapon->query("skill_type")!="sword")
		return notify_fail("「流星幻舞」要拿剑来施展！\n");
	if(weapon->query("flag")==1)
        	return notify_fail("断掉的兵器不能再使用了！\n");
	if(me->query_temp("perform_lx"))
		return notify_fail("你正在使用「流星幻舞」。\n");
	if(!me->query_skill("jiuzhuan-jianjue",1))
		return notify_fail("你还没有学会「九转剑决」！\n");
	if((int)me->query_skill("jiuxuan-dafa",1)<110)
		return notify_fail("你的「九玄大法」还不到家！\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("你的内力修为太低了!\n");
	if((int)me->query("force")<500)
		return notify_fail("你目前的内力状况太差了！\n");
	if((int)me->query_skill("jiuzhuan-jianjue",1)<110)
		return notify_fail("你的「九转剑决」太差了！\n");
	if((int)me->query_skill("sword",1)<120)
		return notify_fail("你的基本剑法还不到家！\n");
	if(time()-me->query_temp("perform_busy_liuxing")<10)
		return notify_fail("你刚施用过「流星幻舞」，真气尚未平复！\n");
	if(me->query_skill("yijian-shu",1)<100)
		return notify_fail("你的弈剑术修为太低了！\n");
    
	message_vision(HIW"\n$N"+HIW+"轻弹了一下手中"+weapon->name()+HIW+"，顺势一抹，"+weapon->name()+HIW+"发出一阵龙吟之声，撒出漫天剑光，剑光中\n"+
                   "$N"+HIW+"的身影爆起一团亮光，有如天外流星，让人无法直视。\n"NOR,me);
		i=me->query_skill("jiuzhuan-jianjue",1)/3;
		me->add_temp("apply/armor",i);
		me->set_temp("perform_lx",1);
		me->add("force",-200);
    
    last_time=me->query_skill("jiuzhuan-jianjue",1)/3;
    if(last_time>=70) last_time=70;
    
	call_out("rid_defence",last_time,me,i);
	return 1;   
  }  
 
void rid_defence(object me,int i)
{
	if(!me) return;
	message_vision(HIY"\n$N"+HIY+"的身上的光芒渐渐散去，身影又能看清了。\n"NOR,me);
	me->add_temp("apply/armor",-i);
	me->delete_temp("perform_lx");
	me->set_temp("perform_busy_liuxing",time());
	return;
}