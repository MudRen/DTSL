//�����ȷ�.���·��ȳ�����书��
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����$wһ����ʹ�������ϸ�꡹������һ����Ӱ����ԼԼ���������޵���$nѹ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
 ([ "action":"$N��$w����һ����һ��[΢�����]�ѽ�$n������·������",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$Nվ��������$w���裬����һ��ǿ�磬һ��[�紵����]ɨ����$n������!",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N���$w����ͷ����������������ס$n,��һ��[ɽ��δ������¥]",
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
   mapping act;
   act=action[random(sizeof(action))];
   return act;
 

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

