/*
NPC ��ʹ�õĽ�������Ϊ�ȼ��ġ�������ͼ��Ľ���---level one.
*/
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����$wð������������ৡ���һ�����治��س�$n��$l������",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
 ([ "action":"$N�����³������Ӳ�ס��ת������$w����һ�Ž�����$n��$l����ȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N����$wһ�ӣ���ʽ�󿪴��أ�ֻ��˲ʱ��㽣Ӱ��$n��$l��������",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N���е�$w����ƫ�棬$w��ת���䣬�����ޱ�һ�д���$n��$l��",
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

