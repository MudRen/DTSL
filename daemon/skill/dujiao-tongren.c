//����� ����������ͭ��
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N���й���ػζ��˼��£�����$w���˸�Բ������$n��$l����ȥ!",
    "apply_factor": 8,
    "name" : "����ͭ��", 
    "damage_type":"����",
  ]),
 ([ "action":"$N����������һ�㣬����$n��ͬʱ����$w˳��һ������$n��$l����ȥ!",
    "apply_factor": 8,
    "name" : "����ͭ��",
    "damage_type":"����",
  ]),
  ([ "action":"$N��ס$w��β�����������ϣ����һ�����͵س�$n��$l����ȥ!",
    "apply_factor": 8,
    "name" : "����ͭ��",
    "damage_type":"����",
  ]),
  ([ "action":"$N���������շ�ת��һ�����������$w��$n��$l��������ȥ!",
    "apply_factor": 8,
    "name" : "����ͭ��",
    "damage_type":"����",
  ])});   



int valid_learn(object me)    
{
	return 1;    
}

int practice_skill(object me)  
{
  
 return 1;  


}


mapping query_action(object me,object weapon)
{
  return action[random(sizeof(action))];
 

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

int skill_damage(object me,object victim)
{
  return 120;
}

