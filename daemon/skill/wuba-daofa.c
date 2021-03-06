//五霸刀法。高丽刀法。
//中级-->高级

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N身形沉稳，手中$w一转，施展出单刀的刀法，一招「推门望月」朝$n的$l处砍去！",
    "apply_factor": 2,
    "name" : "推门望月", 
    "damage_type":"砍伤",
  ]),
 ([ "action":"$N刀锋一转，划过一道圆弧，突然又于其上施展出挑、刺的招数，正是一招「弦外之音」！",
    "apply_factor": 5,
    "name" : "弦外之音",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N刀法突然凌厉，专走险路，赫然竟是马刀的路数，只见一招「无命斩」朝$n的$l砍去！",
    "apply_factor": 10,
    "name" : "无命斩",
    "damage_type":"砍伤",
  ]),
  ([ "action":"正所谓“一寸短，一寸险”，$N突然施展出短刀的路数，欺到$n身前，一招「问鼎中原」朝$n砍去！",
    "apply_factor": 7,
    "name" : "问鼎中原",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N手中$w舞成一道白光，犹如一道盾牌，其中夹杂着几招攻势朝$n砍去，正是一招「万里江山」！",
    "apply_factor": 8,
    "name" : "万里江山",
    "damage_type":"砍伤",
  ]),
  
});   


string *parry_weapon=({

"$N哈哈一笑，一挥手中的$w，硬是格开$n的$v！\n",
"$N刀光舞成圆盾一般，将$n的$v挡在外面！\n",
"$N的$w猛地朝前一劈，浑然不顾及自己的安危，$n一惊，连忙撤回$v。\n",
"$N手中$w一挥，强劲的招式让$n大吃一惊，$v的进攻在顷刻间被化解的一干二净！\n"

});

string *parry_hand=({

"$N冷哼一声，手中的$w朝$n的手掌削去，$n大吃一惊，连忙撤回了进攻的招数！\n",
"$N不顾防守，手中的$w径直朝$n的头部砍去，$n被$N这种拼命打法所惊呆，自己的进攻已经全无威力！\n",
"$N一挥手中的$w，$n只觉得一到霸气扑面而来，连忙撤回进攻的招数。\n",
"$N一声长笑，手中的$w忽然简单一招封住了$n的进攻，好似神来之笔！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

int valid_learn(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("手中无刀，如何学习五霸刀法。\n");
     return 1;  

}

int practice_skill(object me)
{
  object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        
 return 1;  


}


mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];

}

mapping *query_all_action(object me)
{
return action;	
}


string query_type()    
{                      
	return "blade";
}
string query_base()  
{
	return "blade";
}

string *query_perform()
{
	return ({"sanfen","juehun"});
}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}



int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/sanfen"))
  return 150;
  return 80;
}

