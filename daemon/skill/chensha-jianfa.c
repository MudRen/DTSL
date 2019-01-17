//沉沙剑法.
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N手中$w猛地一挥，剑走偏锋，朝$n的$l处刺去！",
    "apply_factor": 4,
    "name" : "沉沙剑法",
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N手腕一沉，剑锋下倾，划了弧线，刺向$n的$l！",
    "apply_factor": 4,
    "name" : "沉沙剑法",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N剑走轻灵，虚刺数下，百虚之中突然一招刺向$n的$l!",
    "apply_factor": 4,
    "name" : "沉沙剑法",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N真气灌注于$w之上，低哼一声，朝$n的$l刺去！",
    "apply_factor": 4,
    "name" : "沉沙剑法",
    "damage_type":"刺伤",
  ]),
 });   


int valid_learn(object me)
{
    if((int)me->query_skill("chensha-jianfa",1) > 400 )
        return notify_fail("单纯的学习已经无法让你从本质上提高了，自己去领悟精髓吧。 \n");
     return 1;  

}

mapping query_action(object me, object weapon)
{
   mapping act;
   act=action[random(sizeof(action))];
   return act;

}
mapping *query_all_action(object me)
{
return action;	
}
string query_type()
{
	return "sword";
}
string query_base()
{
	return "sword";
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{

  return 50;
}
