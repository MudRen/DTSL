//伏鹰枪法。
//中级-->终极武功。

inherit SKILL;
#include <ansi.h>
mapping *action=({
 ([ "action":"$N手中$w左右晃动，一招「月夜迷离」向$n的$l攻去",
    "apply_factor": 2,
    "name" : "月夜迷离",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N大吼一声，$w上下分飞，一招「明月高悬」，$w化为一轮圆月直取$n的$l",
    "apply_factor": 5,
    "name" : "明月高悬",
    "damage_type":"刺伤",
  ]),
  ([ "action":"只见$N手腕一翻，手中$w从意想不到的角度刺向$n的$l，好一招「天高月黑」",
    "apply_factor": 10,
    "name" : "天高月黑",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N使出一招「天狼袭月」，$w一闪，化着奇异的轨迹点向$n的$l",
    "apply_factor": 7,
    "name" : "天狼袭月",
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N错步上前，使出「月影若梦」，手中$w若有若无，淡淡地向$n的$l刺去",
    "apply_factor": 4,
    "name" : "月影若梦",
    "damage_type":"刺伤",
  ]),
([ "action":"$N身行腾空而起，一招「夜月行」，来势奇快，向$n的$l猛插下去",
    "apply_factor": 6,
    "name" : "夜月行",
    "damage_type":"刺伤",
  ]),
});   

string *parry_weapon=({

"$N手中$w一伸，紧接着一晃，抖出数点枪花，封住了$n的$v！\n",
"$N抽身后退，手中$w一横，唰地一声划了个弧线，格开了$n的$v！\n",
"$N手中$w虚空乱点，看似杂乱无章，但却恰倒好处地封住了$n的$v！\n",
"$N低哼一声，手中$w一沉，然后一挑，正好架开$n的$v！\n"

});

string *parry_hand=({

"$N完全不顾$n的进攻，$w直刺向$n的肩膀，$n一惊，连忙收势后退。\n",
"$N手中$w一横，划了一道横线，$n不得不收招后退。\n",
"$N身子一转，躲开了$n的进攻，同时$w回手一刺，$n一惊，连忙后退开来。\n",
"$N聚气凝神，看准$n的进攻之势，猛地刺出，将$n的进攻化为虚有！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}


mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}
mapping *query_all_action(object me)
{
return action;	
}
string *query_perform()
{
  return ({"fengyu","fengsha"});
}
string query_type()    
{                      
	return "spear";
}
string query_base()  
{
	return "spear";
}

int valid_learn(object me)
{

        int i = (int)me->query_skill("fuying-spear", 1);
	object weapon;
        if (i>199) return notify_fail("学就只能学的这里了，剩下的要靠你自己练习了。 \n");
	if(!objectp(weapon=me->query_temp("weapon"))||
		weapon->query("skill_type")!="spear")
			return notify_fail("手中无枪，如何学习伏鹰枪法？\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
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
  if(me->query("perform_quest/fengyu")||
     me->query("perform_quest/fengsha"))
  return 200;
  return 80;
}
