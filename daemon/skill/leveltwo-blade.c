/*
NPC ��ʹ�õĵ�������Ϊ�ȼ��ġ����ǵڶ����ĵ���---level two.
*/
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����$wð������������ৡ���һ�����治��س�$n��$l������",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
 ([ "action":"$N�����³������Ӳ�ס��ת������$w����һ�ŵ�����$n��$l����ȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N����$wһ�ӣ���ʽ�󿪴��أ�ֻ��˲ʱ��㵶�⳯$n��$l��������",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N���е�$w����ƫ�棬$w��ת���䣬�����ޱ�һ�п���$n��$l��",
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
	return "blade";
}
string query_base()  
{
	return "blade";
}

int valid_learn(object me)
{
	return 1;
}
int practice_skill(object me)  
{
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

