//���ߵļ���
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N��ͷ�߸߰����³������ӣ��͵س�$n��$l��ҧȥ��",
        "dodge": 40,
        "force": 90,
        "parry" : 30,
       "damage_type": "ҧ��"
]),

([  "action": "$Nβ��һ�Σ��д���һ�����糯$n��$l����ȥ��",
        "dodge": 35,
        "force": 100,
        "parry" : 20,
        "damage_type": "����"
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
  	message_vision(HIR"$Nһ��ҧס��$n"+HIR+",��$n"+HIR+"��������һ��������˿ڣ�\n"NOR,me,target);
  	target->apply_condition("snake_poison",10);}
  return;
}
  	