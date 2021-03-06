//霸刀

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N手中的$w带起一阵狂风，夹带着风雷之声一招「霸王怒吼」朝$n的$l处砍去！",
    "apply_factor": 3,
    "name": "霸王怒吼",
    "damage_type":"砍伤",
  ]),
 ([ "action":"$N手中$w一沉，招式变缓，颇具帝王之式，一招「九龙飞天」朝$n的$l处斩去！",
    "apply_factor": 10,
    "name": "九龙飞天",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N运气于$w之上，横向一挥，似是拼命般的一招「死里求生」砍向$n！",
    "apply_factor": 5,
    "name": "死里求生",
    "damage_type":"震伤",
  ]),
  ([ "action":"$N手中$w如同流星暴雨，毫不停歇地朝$n砍去，正是一招「八面伏龙」！",
    "apply_factor": 7,
    "name": "八面伏龙",
    "damage_type":"砍伤",
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

        int i = (int)me->query_skill("badao", 1);
     object weapon;

        if (i>=200) return notify_fail("学就只能学的这里了，剩下的要靠你自己练习了。 \n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
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

string *query_perform()
{
	return ({"zongheng"});
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
  if(me->query("perform_quest/badao"))
  return 200;
  return 100;
}
