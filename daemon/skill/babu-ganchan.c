// 八步赶蝉
//NPC skills

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n一招[流星追月]躲开了$N的攻击。"
]),
([      "action" : "$n身行不住地晃动,一招[虚幻无影]躲开了$N的攻式。"
]),
([      "action" : "$n忙使出一招[清风踏月],闪了开来!"
]),
([      "action" : "$n凌空纵起,一招[明月在天]越到了$N的头顶。"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}



string query_type()
{
	return "base";
}

string query_base()
{
	return "dodge";
}


int valid_learn(object me)  
{

        int i = (int)me->query_skill("babu-ganchan", 1);
        if (i>=400) return notify_fail("学就只能学的这里了，剩下的要靠你自己领悟了。 \n");
        return 1;
}

int query_dodge(object me)
{
	return 20;
}
