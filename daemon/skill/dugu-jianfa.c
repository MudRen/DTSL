//独孤剑法.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N冷哼一声，剑法突然加快，如同万点光芒一般，刺向$n的$l！",
    "apply_factor": 4,
    "name" : "独孤剑法", 
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N剑式突然变缓，剑身发出浓重的杀气，刷地一下突然刺向$n的$l！",
    "apply_factor": 4,
    "name" : "独孤剑法",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N纵身跃起，手中$w化做万点光芒，直刺向$n的$l！",
    "apply_factor": 4,
    "name" : "独孤剑法",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N冷笑一声，剑法突然忽快忽慢，如同鬼魅一般刺向$n的$l！",
    "apply_factor": 4,
    "name" : "独孤剑法",
    "damage_type":"刺伤",
  ])});   






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
	return "sword";
}
string query_base()  
{
	return "sword";
}

int valid_learn(object me)
{
	object weapon;
	if(objectp(weapon=me->query_temp("weapon")))
		if(weapon->query("skill_type")!="sword")
			return notify_fail("手中无剑,如何学习[独孤剑法]?\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  
  return 60;
}
