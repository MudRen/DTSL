//�廢���ŵ�.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N���лζ�,�͵�һ��[�ͻ���ɽ]����$n��$l��",
    "apply_factor": 5,
    "name" : "����", 
    "damage_type":"����",
  ]),
 ([ "action":"$N�����͵���ǰһ��,�������һɨ,һ��[��Х����]�ٵ���$n��$l��ȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N�ڿ�Խ��,�ӵ���տ���,����һ��[�ͻ�����]��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N���һ��,һ��[�ͻ�����]������$n��ȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ])});   



int valid_learn(object me)    //��learn����.
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
	return "blade";
}
string query_base()  
{
	return "blade";
}

