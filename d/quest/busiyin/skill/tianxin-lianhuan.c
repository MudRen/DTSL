//��������.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N˫�Ʋ��룬��ע����������ɽ�����㳯$nѹȥ��",
    "dodge":30,  
    "damage":180, 
	"parry":20,  
    "damage_type":"����",
  ]),
 ([ "action":"$N����һ�ᣬ������ָĴָ����ָ�ص���ֻ����������һ��һ����������$n!",
    "dodge":30,
    "damage":160,
	"parry":40,
    "damage_type":"����",
  ]),
  ([ "action":"$N˫�����У�����������״��һ��������$n�͵�ѹȥ��",
    "dodge":30,
    "damage":150,
	"parry":50,
    "damage_type":"����",
  ]),
  ([ "action":"$N��������ͻȻһ��Ϊ�����仯���죬��$n��������·ץȥ��",
    "dodge":30,
    "damage":170,
	"parry":30,
    "damage_type":"ץ��",
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
	return "hand";
}
string query_base()  
{
	return "strike";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
