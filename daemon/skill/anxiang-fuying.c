//暗香浮影。宋家堡武功。

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n身行后退，潇洒自如，一招「香飘万里」轻轻躲开了$N的攻击。"
]),
([      "action" : "$n身行猛地向上跃起，犹如飞天鸿鹄，一招「浮影无踪」闪到了$N的身旁。"
]),
([      "action" : "$n有如轻烟，虚无飘渺，一招「无香无影」轻松地躲开了$N的攻击！"
]),
([      "action" : "$n脚踏玄步，暗合数相之里，令人琢磨不定，一招「万影无常」躲开了$N的攻击。"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{

        int i = (int)me->query_skill("anxiang-fuying", 1);
        if (i>=400) return notify_fail("学就只能学的这里了，剩下的要靠你自己练习了。 \n");
    
	   return 1;
}



int practice_skill(object me)
{
     
	
	return 1;
}

string query_type()
{
	return "dodge";
}
string query_base()
{
	return "dodge";
}

int query_dodge(object me)
{
	return 40;	
	
}
