//毒蛇的技能
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N将头高高昂起，吐出红信子，猛地朝$n的$l处咬去！",
        "dodge": 40,
        "force": 90,
        "parry" : 30,
       "damage_type": "咬伤"
]),

([  "action": "$N尾巴一晃，夹带着一股旋风朝$n的$l处打去！",
        "dodge": 35,
        "force": 100,
        "parry" : 20,
        "damage_type": "瘀伤"
]),

});


mapping query_action(object me)  
{
       return action[random(sizeof(action))];
}

string query_type() 
{
	return "hand";
}

string query_base()
{
	return "strike";//no use
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

void hit_ob(object me,object target)
{
  if(!target->query_condition("snake_poison")){
  	message_vision(HIR"$N一口咬住了$n"+HIR+",在$n"+HIR+"身上留下一个深深的伤口！\n"NOR,me,target);
  	target->apply_condition("snake_poison",10);}
  return;
}
  	