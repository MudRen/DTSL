//���罣��
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����$w��������������һ�󺮷磬�͵ش���$n��$l��",
    "dodge":35,  
    "damage":180, 
	"parry":20,  
    "damage_type":"����",
  ]),
 ([ "action":"$N����$w���˸�����������һ����ֻ��һ�㺮����$n��$l������",
    "dodge":30,
    "damage":160,
	"parry":40,
    "damage_type":"����",
  ]),
  ([ "action":"$N���з��ٻζ�������$w���˸����ߣ�ֱ��$n��$l��ȥ��",
    "dodge":30,
    "damage":150,
	"parry":50,
    "damage_type":"����",
  ]),
  ([ "action":"$N�ͺ�һ��������$w��������һ�㡰ৡ���һ������$n��$l!",
    "dodge":30,
    "damage":170,
	"parry":30,
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

string *query_perform()
{
	return ({"none"}); 
}

string query_type()    
{                   
	return "sword";
}
string query_base()  
{
	return "sword";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
