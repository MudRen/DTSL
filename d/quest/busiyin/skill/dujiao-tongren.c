//����� ����������ͭ��
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N���й���ػζ��˼��£�����$w���˸�Բ������$n��$l����ȥ!",
    "dodge":30,  
    "damage":180, 
	"parry":20, 
    "damage_type":"����",
  ]),
 ([ "action":"$N����������һ�㣬����$n��ͬʱ����$w˳��һ������$n��$l����ȥ!",
    "dodge":30,
    "damage":170,
	"parry":30,
    "damage_type":"����",
  ]),
  ([ "action":"$N��ס$w��β�����������ϣ����һ�����͵س�$n��$l����ȥ!",
    "dodge":30,
    "damage":160,
	"parry":40,
    "damage_type":"����",
  ]),
  ([ "action":"$N���������շ�ת��һ�����������$w��$n��$l��������ȥ!",
    "dodge":33,
    "damage":190,
	"parry":10,
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

string *query_perform()
{
	return ({"none"});
}

