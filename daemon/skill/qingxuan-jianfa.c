//��������.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N���лζ�,���߾Ź�����֮ʽ,һ��[������]����$n��",
    "apply_factor": 5,
    "name" : "����", 
    "damage_type":"����",
  ]),
 ([ "action":"$N�����͵���ǰһ��,�������һɨ,һ��[��������]�ٽ���$n�Ķ�ͷ��ȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N�ڿ�Խ��,�ӽ���մ���,����һ��[�������]��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N��������,��������һ��Բ��,һ��[������ʵ]����$n�������Ѩ��",
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
	return "sword";
}
string query_base()  
{
	return "sword";
}

