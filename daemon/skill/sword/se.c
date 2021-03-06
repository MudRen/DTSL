//色空剑法
//色字决
//by rzy 02.09.21

#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
	int i;
	object weapon;
	weapon=me->query_temp("weapon");
	
	if(!me->is_fighting(target))
		return notify_fail("「色字决」要在战斗中施展！\n");
	if((int)me->query("PKS",1)>=5)
         return notify_fail("你罪孽深重，无法使用此绝技。\n");
	if(!weapon || weapon->query("skill_type")!="sword")
		return notify_fail("「色字决」要拿剑来施展！\n");
	if(weapon->query("flag")==1)
        	return notify_fail("断掉的兵器不能再使用了！\n");
	if(me->query_temp("perform_se"))
		return notify_fail("你正在使用「色字决」。\n");
	if(!me->query_skill("sekong-jianfa",1))
		return notify_fail("不会「色空剑法」如何使用「色字决」？\n");
	if((int)me->query_skill("qingxin-force",1)<110)
		return notify_fail("你的「清心普善诀」还不到家！\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("你的内力修为太低了!\n");
	if((int)me->query("force")<500)
		return notify_fail("你目前的内力状况太差了！\n");
	if((int)me->query_skill("sekong-jianfa",1)<110)
		return notify_fail("你的「色空剑法」太差了！\n");
	if((int)me->query_skill("sword",1)<110)
		return notify_fail("你的基本剑法还不到家！\n");
	if(time()-me->query_temp("perform_busy_se")<10)
		return notify_fail("你刚施用过「色字决」，真气尚未平复！\n");
    
	message_vision(HIC"\n$N"+HIC+"曼妙的姿态不断变化，手中"+weapon->name()+HIC+"微微探前，抖出点点剑光，转眼间点点剑光化做漫天光雨，\n"+
                   "$N"+HIC+"身形在光雨中变的模糊不清，却凭添了神秘的美丽，「色字决」笼罩范围内的一切都变的如 \n"+
                   "同神话仙境，美丽的让人无法相信！\n"NOR,me);
		i=me->query_skill("sekong-jianfa",1)/5;
		me->add_temp("apply/armor",i);
		me->set_temp("perform_se",1);
		me->add("force",-200);

	call_out("rid_defence",i,me,i);
	return 1;   
  }  
 
void rid_defence(object me,int i)
{
	if(!me) return;
	message_vision(HIC"\n漫天光雨散去，$N"+HIC+"的身形又清晰可辨了。\n"NOR,me);
	me->add_temp("apply/armor",-i);
	me->delete_temp("perform_se");
	me->set_temp("perform_busy_se",time());
	return;
}