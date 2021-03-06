// 幽明掌。独孤霸的掌法。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": HIB"$N身行诡异，闪动于$n的四周，猛地使出一招[幽魂问心]拍向$n的$l!"NOR,
        "apply_factor": 5,
        "name" : "招数",
       "damage_type": "瘀伤"
]),

([  "action": HIB"$N身行左右闪动，令$n琢磨不定，$N突然有如鬼魅般使出一招[突现鬼影]打向$n的$l！"NOR,
        "apply_factor": 5,
        "name" : "招数",
        "damage_type": "瘀伤"
]),

([      "action": HIB"$N面上寒气笼罩，令$n觉得动作一滞，$N猛地一招[鬼笑惊魂]打向$n的$l！"NOR,
        "apply_factor": 5,
        "name" : "招数",
        "damage_type": "瘀伤"
]),

([  "action": HIB"$N左右双掌分飞，如同幽灵一般，一招[鬼火索命]拍向$n的$l！"NOR,
        "apply_factor": 5,
        "name" : "招数",
        "damage_type": "瘀伤"
]),

});


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
     	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习幽明掌。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习[幽明掌]!\n");
     return 1;
}



string query_type() 
{
	return "hand";
}

string query_base()
{
	return "strike";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

