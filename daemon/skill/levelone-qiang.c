inherit SKILL;
#include <ansi.h>
mapping *action=({
 ([ "action":"$N����$wһ������������$n���ţ���ɤ��ǰ��",
    "apply_factor": 5,
    "name" : "ǹ��",
    "damage_type":"����",
  ]),
  ([ "action":"$Nһ���粽��$w���·ַɣ�����ǹӰ�Ƚ�����������ס��",
    "apply_factor": 5,
    "name" : "ǹ��",
    "damage_type":"����",
  ]),
  ([ "action":"$Nһ��ǹ�ѣ�ž����һ���������ǹ�����������ң�����ʵʵ����$nȫ��Ҫ��",
    "apply_factor": 5,
    "name" : "ǹ��",
    "damage_type":"����",
  ]),([ "action":"$N���һ����$w������һ�����⣬��ǹ�������ƵĻ����ռ䣬����$n",
    "apply_factor": 5,
    "name" : "ǹ��",
    "damage_type":"����",
  ]),
});   

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
		return 0;
	else return action[i-1];
}
