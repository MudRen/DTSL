//�ؼ�ﵷ���
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N��һ��ﵣ�һ��[̩ɽѹ��]����$n��ͷ����",
    "apply_factor": 5,
    "name" : "����",  
    "damage_type":"����",
  ]),
 ([ "action":"$N���лζ�,���ɵĶ�������,ͬʱһ��[����ٵ�]����$n���ؿڣ�",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N���и�ﵷ�������,����Խ������,����һ��[��ͷ����]����$n��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N��ǰ��������,���ֱ��,һ��[���߳���]����$n�����ѣ�",
    "apply_factor": 5,
    "name" : "����",
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


string query_type()   
{                     
	return "jian";
}
string query_base() 
{
	return "jian";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

