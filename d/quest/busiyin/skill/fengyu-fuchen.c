//����˫�� ������
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N����$w����һ�ӣ�$nֻ����һ��ǿ�����������Լ��͵�������",
    "dodge":30,  
    "damage":180, 
	"parry":20,  
    "damage_type":"����",
  ]),
 ([ "action":"$N����$wת�˼�ת����ס��$n�Ĺ��ƣ�ͬʱ$w��β����$n��$l��ײȥ��",
    "dodge":30,
    "damage":160,
	"parry":40,
    "damage_type":"����",
  ]),
  ([ "action":"$N������������������$w��ע������������ʽ����ճ�$n��$l����ȥ��",
    "dodge":30,
    "damage":150,
	"parry":50,
    "damage_type":"����",
  ]),
  ([ "action":"$N�����³�����ס��ת��$w���������㳯$n��$l����ȥ�����������̳���",
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
	return "whip";
}
string query_base()  
{
	return "whip";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
