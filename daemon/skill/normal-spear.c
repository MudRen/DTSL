inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����$wͻȻ�̳���һ��[���߳���]����$n��$l��",
    "apply_factor": 5,
    "name" : "����", 
    "damage_type":"����",
  ]),
 ([ "action":"$N����$wһ�ᣬ��ס$n�Ĺ�����$wβ����ǰһӭ��ֱײ��$n��$l!",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N���е�$w��Ȼ������ǧӰ�ӣ�һ��[���񳯷�]��$n��ȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N������ˣ�ͻȻ�������һ����һ��[����ǹ]����$n��$l��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ])});   




mapping query_action(object me,object weapon)
{
   
return action[random(sizeof(action))];  
 

}



string query_type()    
{                     
	return "spear";
}
string query_base()  
{
	return "spear";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return action[random(sizeof(action))];
	else return action[i-1];
}

