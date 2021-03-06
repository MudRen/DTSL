// 如来神掌。静念禅院。
//中极-->终极武功

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N面含微笑，不带有丝毫的杀意，招数缓慢凝重，似有千钧之力，\n"+
                  "缓缓朝$n的$l处拍去，$n顿觉压力重重！",
        "apply_factor": 2,
    		"name" : "佛光普照",
       "damage_type": "瘀伤"
]),

([      "action": "$N的手掌不断变换，幻化出数个形状各异的掌形，$n吃惊之余，早\n"+
                  "已身陷其中，只觉陷入了一个思网之中，四周压力重重！",
        "apply_factor": 5,
    		"name" : "佛法无边",
        "damage_type": "瘀伤"
]),

([      "action": "$N左掌收回，右掌看似缓慢地推出，只听“波”的一声，一股强大\n"+
                  "的气流朝$n撞去！",
        "apply_factor": 10,
    		"name" : "佛光破魔",
        "damage_type": "瘀伤"
]),

([      "action": "$N突然纵身跃起，$n吃惊之余，只见$N一个旋身，双掌不断变换，\n"+
                  "只见数个手掌从天而降朝$n打来！",
        "apply_factor": 7,
    		"name" : "灵光天降",
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
    
    if(me->query("chanyuan_skill")!="rulai-shenzhang")
    return notify_fail("你不能学习这个技能！\n");
    
    if((int)me->query("PKS",1)>=5)
    return notify_fail("你只觉得自己作孽深重，不能在继续学习下去了！\n");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习如来神掌。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(me->query("chanyuan_skill")!="rulai-shenzhang")
      return notify_fail("你不能练习这个技能！\n");
      
      if((int)me->query("PKS",1)>=5)
    return notify_fail("你只觉得自己作孽深重，不能在继续练习下去了！\n");
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习如来神掌。\n");
     return 1;
}

string *query_perform()
{
	return ({"pudu","pomo"});   
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
  if(me->query("perform_quest/pudu"))
  return 180;
  return 80;
}

void hit_ob(object me,object victim)
{
   if(!me->query_temp("actionp_hit/pomo"))
   return;
   
   "/daemon/skill/effskill/pomo.c"->hit_ob(me,victim);
   return;
}