//���½���.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N���һ��������ͻȻ�ӿ죬��ͬ����âһ�㣬����$n��$l��",
    "apply_factor": 4,
    "name" : "���½���", 
    "damage_type":"����",
  ]),
 ([ "action":"$N��ʽͻȻ�仺��������Ũ�ص�ɱ����ˢ��һ��ͻȻ����$n��$l��",
    "apply_factor": 4,
    "name" : "���½���",
    "damage_type":"����",
  ]),
  ([ "action":"$N����Ծ������$w��������â��ֱ����$n��$l��",
    "apply_factor": 4,
    "name" : "���½���",
    "damage_type":"����",
  ]),
  ([ "action":"$N��Цһ��������ͻȻ�����������ͬ����һ�����$n��$l��",
    "apply_factor": 4,
    "name" : "���½���",
    "damage_type":"����",
  ])});   






mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}
mapping *query_all_action(object me)
{
return action;	
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
	object weapon;
	if(objectp(weapon=me->query_temp("weapon")))
		if(weapon->query("skill_type")!="sword")
			return notify_fail("�����޽�,���ѧϰ[���½���]?\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  
  return 60;
}
