//幽月掌法。
//低等级

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N右掌探出，只觉一阵寒气，一招「冷月拂面」拍向$n的$l！",
        "apply_factor": 2,
        "name" : "冷月拂面",
       "damage_type": "震伤"
]),

([  "action": "$N掌化刀式，令$n只觉得寒气扑面，一招「吴刚斫桂」砍向$n的$l处！",
        "apply_factor": 3,
        "name" : "吴刚斫桂",
        "damage_type": "震伤"
]),

([      "action": "$N身行突然变快，四方闪动，猛地一招「月影悠悠」拍向$n的$l！",
        "apply_factor": 4,
        "name" : "月影悠悠",
        "damage_type": "瘀伤"
]),

([  "action": "$N左掌拍向$n，突然身行猛地一转，绕到$n身后，右掌一招「月华万道」向$l拍了过去！",
        "apply_factor": 5,
        "name" : "月华万道",
        "damage_type": "震伤"
]),

});

string *parry_weapon=({

"$N姿态幽雅，手掌划了一道不可思异的轨迹，挡开了$n的$v，$n不禁一惊。\n",
"$N的手掌竟然朝$n的$v迎去，接触的刹那，手掌似乎生出的粘力，带开了$n的$v。\n",
"$N一侧头，身形朝旁边一闪，一推$v的手腕，避开了$n的进攻。\n",
"$N的掌势轻轻一带，化解了$n的进攻！\n"

});

string *parry_hand=({

"$N的双掌迎上$n的进攻，只听碰地一声，双方各退后几步。\n",
"$N掌法严谨，丝毫不漏破绽，$n见势不好，连忙后退开来！\n",
"$N低喝一声，双掌一挥，档住了$n的进攻。\n",
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
    
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习幽月掌法。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习幽月掌法。\n");
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
