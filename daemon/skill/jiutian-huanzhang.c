// 九天幻掌.阴癸派


#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N的身行飘忽不定，如同幻影一般，闪到了$n的身后，一招「无影无踪」拍向$n的$l!",
        "apply_factor": 2,
        "name" : "无影无踪",
       "damage_type": "瘀伤"
]),

([  "action": "$N双掌如同莲花一般，绽放开来，正是一招「莲花探影」，击向$n的$l!",
        "apply_factor": 3,
        "name" : "莲花探影",
        "damage_type": "瘀伤"
]),

([      "action": "$N身行绕着$n急速转动，忽然出掌，正是一招「飞天幻掌」打向$n的$l!",
        "apply_factor": 4,
        "name" : "飞天幻掌",
        "damage_type": "瘀伤"
]),

([  "action": "$N双掌上下番飞，如同化成了千万个手掌，正是一招「九天万幻」拍向$n的$l处!",
        "apply_factor": 5,
        "name" : "九天万幻",
        "damage_type": "瘀伤"
]),

});

string *parry_weapon=({

"只见$N不顾$n的$v，架住了$n的手腕，同时手肘向前一撞，$n不得不后退开来。\n",
"$N完全不顾$n的$v，反而以更快的速度打向$n的$l，好象围魏救赵般化解了$n的进攻。\n",
"$N双掌如同莲花一般，绽放开来，封住了$n的进攻。\n",
"$N的掌势轻轻一带，化解了$n的进攻！\n"

});

string *parry_hand=({

"$N的手掌迎上$n的进攻，只听碰地一声，双方各退后几步。\n",
"$N掌法错乱，如同万千幻影，$n见势不好，连忙后退开来！\n",
"$N双掌诡异一般伸出，猛地抓向$n的手腕，$n连忙后退，惊出一身冷汗。\n",
"$N的掌势轻轻一带，化解了$n的进攻！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}
   

mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}
mapping *query_all_action(object me)
{
return action;	
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习九天幻掌。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习九天幻掌。\n");
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
int skill_damage(object me,object victim)
{
  
  return 40;
}
