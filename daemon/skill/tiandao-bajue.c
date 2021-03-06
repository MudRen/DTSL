//天刀八诀。宋家堡武功。
//中级-->终极武功。

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N以讯雷不及掩耳之式，猛地挥出一刀，正是一招「天风环佩」砍向$n的$l处！",
    "apply_factor": 2,
    "name" : "天风环佩",
    "damage_type":"砍伤",
  ]),
 ([ "action":"$N手中$w一闪，身行竟然晃到了$n的身后，一招「潇汀水云」砍向$n的$l!",
    "apply_factor": 5,
    "name" : "潇汀水云",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N手中$w晃出一片刀影，突然从中挥出一刀，一招「石上流泉」猛地砍向$n的$l处！",
    "apply_factor": 10,
    "name" : "石上流泉",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N身行绕着$n不住地转动，突然砍出一刀，正是一招「梧叶舞秋风」砍向$n的$l！",
    "apply_factor": 7,
    "name" : "梧叶舞秋风",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N一横$w,挡开$n的进攻，回首一招「天刀无情」砍向$n的$l处！",
     "apply_factor": 4,
     "name" : "天刀无情",
     "damage_type":"砍伤",
    ]),
  ([ "action":"$N身行猛地纵起，$w在手中挽了刀花，向下一招「天刀迎客」砍向$n的$l！",
     "apply_factor": 6,
     "name" : "天刀迎客",
     "damage_type":"砍伤",
    ]),  
   ([ "action":"$N身行下沉，步法稳健，挥动$w向上砍去，一招「天刀寻雨」砍向$n的$l！",
     "apply_factor": 3,
     "name" : "天刀寻雨",
     "damage_type":"砍伤",
    ]), 
   ([ "action":"$N手中$w四方各砍三刀，最后一刀直刺向$n的$l,正是一招「天刀问心」！",
     "apply_factor": 8,
     "name" : "天刀问心",
     "damage_type":"刺伤",
    ]), 
 });   

string *parry_weapon=({

"$N挥舞起手中的$w，带着一股霸气，一招格开了$n的$v！\n",
"$N手中$w横挥一刀，接着又竖砍一刀，一个十字形刀光将$n的$v挡在外面！\n",
"$N丝毫也不退让，手中的$w反而攻击上来，迫得$n撤回了手中的$v。\n",
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
        
	if(me->query_skill("badao",1)>0)
        	return notify_fail("你学习了霸刀，无法再学习天刀八诀！\n");

	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("手中无刀，如何学习天刀八诀。\n");
     return 1;  

}

int practice_skill(object me)
{
  object weapon;
	
	if(me->query_skill("badao",1)>0)
        	return notify_fail("你学习了霸刀，无法再学习天刀八诀！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        
 return 1;  


}


mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];

}

mapping *query_all_action(object me)
{
return action;	
}

string *query_perform()
{
	return ({"bajue","daoyi"});
}
string query_type()
{
	return "blade";
}
string query_base()
{
	return "blade";
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/bajue"))
  return 210;
  return 100;
}
