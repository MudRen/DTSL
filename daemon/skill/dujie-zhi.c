// 渡劫指。静念禅院。
//中极-->终极武功

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N身形向后一闪，右手食指使出一招「金针问心」刺向$n的$l！",
        "apply_factor": 2,
        "name" : "金针问心",
       "damage_type": "刺伤"
]),

([  "action": "$N身形猛地越起，双手食指向$n的$l刺来，正是一招「佛从天降」！",
        "apply_factor": 5,
        "name" : "佛从天降",
        "damage_type": "刺伤"
]),

([      "action": "$N双手食指忽然连连闪动，令$n琢磨不定，刺向$n的全身要穴，正是一招「普渡众生」！",
        "apply_factor": 10,
        "name" : "普渡众生",
        "damage_type": "刺伤"
]),

([  "action": "$N左手食指向$n的面门一晃，右手食指猛地从下面伸出，一招「无相渡劫」刺向$n的$l！",
        "apply_factor": 7,
        "name" : "无相渡劫",
        "damage_type": "刺伤"
]),

});

string *parry_weapon=({

"$N面带微笑，手指呈捻花之形，顿时使$n的$v有无从下手之感！\n",
"$N手指微微一划，举轻若重地卸开了$n的进攻！\n",
"$N双指灵活闪动，$n只觉得自己的进攻落空了，险些跌倒在地。\n",
"$N的手指朝$n的手腕刺去，$n急忙后退，手中的$v险些被击落在地！\n"

});

string *parry_hand=({

"$N指法变换无常，以守代攻地架开了$n的进攻。\n",
"$N微微一笑，手指一划，$n的进攻已经被冰消瓦解！\n",
"$N手指一划，随后闪开，寻找着进攻的机会。\n",
"$N指法不住变换，虽是简单的招式，却封住了$n的全部进攻之力！\n"

});

mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}
mapping *query_all_action(object me)
{
return action;	
}

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

int valid_learn(object me)
{
    if(me->query("chanyuan_skill")!="dujie-zhi")
    return notify_fail("你不能学习这个技能！\n");
    if((int)me->query("PKS",1)>=5)
    return notify_fail("你只觉得自己作孽深重，不能在继续学习下去了！\n");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习渡劫指。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(me->query("chanyuan_skill")!="dujie-zhi")
    return notify_fail("你不能练习这个技能！\n");
      if((int)me->query("PKS",1)>=5)
    return notify_fail("你只觉得自己作孽深重，不能在继续练习下去了！\n");
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习渡劫指。\n");
     return 1;
}

string *query_perform()
{
	return ({"liudao","yizhi"});   
}


string query_type() 
{
	return "hand";
}

string query_base()
{
	return "finger";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/liudao"))
  return 200;
  return 80;
}
