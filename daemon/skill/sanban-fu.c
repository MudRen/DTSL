//for ��ҧ��.���師.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N�첽��ǰ������һ��[������],��$n�Դ���ȥ��",
    "apply_factor": 5,
    "name" : "����",  
    
    "damage_type":"����",
  ]),
 ([ "action":"$N�󸫺���,����һ��[���Դ�],����$n��ͷ����",
    "apply_factor": 5,
    "name" : "����",
   "damage_type":"����",
  ]),
  ([ "action":"$Nһ����,˵��:���ˣ�",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ])
  });   


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
	return "axe";
}
string query_base() 
{
	return "axe";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

