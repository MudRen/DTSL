//��������.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N˫�Ʋ��룬��ע����������ɽ�����㳯$nѹȥ��",
    "apply_factor": 5,
    "name" : "����",  
    "damage_type":"����",
  ]),
 ([ "action":"$N����һ�ᣬ������ָĴָ����ָ�ص���ֻ����������һ��һ����������$n!",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N˫�����У�����������״��һ��������$n�͵�ѹȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N��������ͻȻһ��Ϊ�����仯���죬��$n��������·ץȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"ץ��",
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
  
  return 100;
}
