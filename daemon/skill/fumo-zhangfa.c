//伏魔杖法。净念禅院武功。
//中级-->终极武功。

inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N看清$n的来势，不慌不忙的使出伏魔杖法中的「诸佛空相」，手中的$w幻起漫天杖影，守的水泄不通！",
    "apply_factor": 2,
    "name" : "诸佛空相", 
    "damage_type":"砸伤",
  ]),
 ([ "action":"$N双脚盘旋，脚踩九宫八卦之势，晃动身行，一招「除魔伏妖」砸向$n的$l！",
    "apply_factor": 5,
    "name" : "除魔伏妖", 
    "damage_type":"砸伤",
  ]),
  ([ "action":"$N身行后退，钢杖挥舞，生成一阵强风，一招「佛光万道」守中带攻地朝$n打去！",
    "apply_factor": 10,
    "name" : "佛光万道",
    "damage_type":"砸伤",
  ]),
  ([ "action":"$N大喝一声，手中$w急速旋转，只见$w夹带着一股强大气劲朝$n的$l处打去！",
    "apply_factor": 7,
    "name" : "佛法无边",
    "damage_type":"砸伤",
  ])});   
  
string *parry_weapon=({

"$N一声低喝，用$w架住了$n的$v，震得$n退后了几步！\n",
"$N一抡$w，挥舞出一个圆圈，将$n的$v挡了出去！\n",
"$N一横$w，以简单有效的招数架住了$n的$v！\n",
"$N将$w挥舞开来，$n连忙退后，使$v无从下手！\n"

});

string *parry_hand=({

"$N看准机会，手中$w一横，恰好封住了$n的进攻。\n",
"$N一抡手中$w，以攻代守朝$n砸去，$n连忙闪开！\n",
"$N手中$w一挥，随后闪开，寻找着进攻的机会。\n",
"$N手中$w一横，虽是简单的招式，却封住了$n的全部进攻之力！\n"

});



int valid_learn(object me)    
{
    object weapon;
    
    if(me->query("chanyuan_skill")!="fumo-zhangfa")
    return notify_fail("你不能学习这个技能！\n");
    if((int)me->query("PKS",1)>=5)
    return notify_fail("你感到罪孽深重，不能再继续学习「伏魔杖法」了！\n");
	weapon=me->query_temp("weapon");
	if(!objectp(weapon))
		return notify_fail("手中无杖，如何学习「伏魔杖法」？\n");
	if((string)weapon->query("skill_type")!="staff")
		return notify_fail("你使用的武器不对！\n");
	return 1;    


}

int practice_skill(object me)  
{
   object weapon;
   weapon=me->query_temp("weapon");
   if(me->query("chanyuan_skill")!="fumo-zhangfa")
    return notify_fail("你不能练习这个技能！\n");
   if((int)me->query("PKS",1)>=5)
    return notify_fail("你感到罪孽深重，不能再继续练习「伏魔杖法」了！\n");
   if(!objectp(weapon))
		return notify_fail("手中无杖，如何练习「伏魔杖法」？\n");
	if((string)weapon->query("skill_type")!="staff")
		return notify_fail("你使用的武器不对！\n");
 return 1;  


}


mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

mapping *query_all_action(object me)
{
return action;	
}

string query_type()    
{                      
	return "staff";
}
string query_base()  
{
	return "staff";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

string *query_perform()
{
	return ({"fumo","xiangyao"});
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/fumo"))
  return 200;
  return 80;
}
