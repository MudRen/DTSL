//九字真言。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N不见半点情绪表情的波动，仿如入静的高僧，暗施出“不动根本印”，一股气劲自周身弥散开来。\n",
        "apply_factor": 2,
        "name" : "不动根本印",
       "damage_type": "瘀伤"
]),
([      "action": "$N手捏大金刚轮印，脸上红光闪现，只见一股热浪朝$n涌去！",
        "apply_factor": 6,
        "name" : "大金刚轮印",
       "damage_type": "瘀伤"
]),
([  "action": "$N一无所惧，长笑一声，倏又往右闪去，左手拍向$n，同时右手暗捏狮子印，沉喝一声“咄”！",
        "apply_factor": 10,
        "name" : "外狮子印",
        "damage_type": "瘀伤"
]),
([  "action": "$N右手暗捏内狮子印，左手一挥，只见一股气墙朝$n的拍去！",
        "apply_factor": 7,
        "name" : "内狮子印",
        "damage_type": "瘀伤"
]),

([  "action": "$N由内缚印改为外缚印，拇指改置外侧，劲气疾吐，$n登时应印而加速横翻过去！",
        "apply_factor": 6,
        "name" : "外缚印",
        "damage_type": "瘀伤"
]),

([      "action": "$N内缚印体内脉道真气交战，早严阵以待的真气对入侵的内劲迎头痛击！",
        "apply_factor": 4,
        "name" : "内缚印",
        "damage_type": "瘀伤"
]),

([  "action": "$N按捏智拳印，突然拳法突变，宛如漫天流星，朝$n的$l处打去！",
        "apply_factor": 3,
        "name" : "智拳印",
        "damage_type": "瘀伤"
]),
([  "action": "$N按捏日轮印，手掌交错之间，四周已是热浪翻滚，几阵内劲朝$n涌去！",
        "apply_factor": 8,
        "name" : "日轮印",
        "damage_type": "瘀伤"
]),
([  "action": "$N按捏宝瓶印，宝瓶气拳劲再非高度集中的一团，而是像一堵墙般直朝$n压过去！",
        "apply_factor": 9,
        "name" : "宝瓶印",
        "damage_type": "瘀伤"
]),

});

string *parry_weapon=({

"$N面带微笑，手掌似轻似重，顿时使$n的$v有无从下手之感！\n",
"$N手掌微微一带，举轻若重地卸开了$n的进攻！\n",
"$N一挥手掌，$n只觉得自己的进攻落空了，险些跌倒在地。\n",
"$N的手掌朝$n的手腕拍去，$n急忙后退，手中的$v险些被拍落在地！\n"

});

string *parry_hand=({

"$N手掌变换无常，以守代攻地架开了$n的进攻。\n",
"$N微微一笑，手掌一挥，$n的进攻已经被冰消瓦解！\n",
"$N手掌一挥，随后闪开，寻找着进攻的机会。\n",
"$N手掌不住变换，虽是简单的招式，却封住了$n的全部进攻之力！\n"

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
    if(me->query_temp("weapon"))
    return notify_fail("手中拿着武器，如何学习九字真言？");
    return 1;  
}

int practice_skill(object me)
{
     if(me->query_temp("weapon"))
    return notify_fail("手中拿着武器，如何练习九字真言？");
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

string *query_perform()
{
  return ({"budong","jingang","shizi","fu","zhiquan"});
}


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/jzzy"))
  return 150;
  if(me->query_skill("jiuzi-zhenyan",1)>180)
  return 220;
  return 120;
}
