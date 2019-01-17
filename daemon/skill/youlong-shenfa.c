//游龙身法。

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n身形后退数步，向旁边一闪，躲开了$N的进攻。"
]),
([      "action" : "$n凌空纵起，身体不住旋转，一式「游龙飞天」躲开了$N的攻击。"
]),
([      "action" : "$n脚猛地一跺地，激起片片尘土，顺式一招「游龙戏水」闪开$N的进攻!"
]),
([      "action" : "$n身体不住飞旋，从$N头顶掠过，正是一招「龙游九天」！"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
    
        int i = (int)me->query_skill("youlong-shenfa", 1);
        if (i>199) return notify_fail("学就只能学的这里了，剩下的要靠你自己练习了。 \n");
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

string *query_perform()
{
   return ({"qunxiao"});
}

int query_dodge(object me)
{
	return 30;
}
