// ̫����֡�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�����������������һ�Σ������͵س�$n��$l����ȥ!",
        "apply_factor": 5,
        "name" : "����",
       "damage_type": "����"
]),

([  "action": "$N�����³�������һ�����ִ������·�б���ȥ���͵ش���$n��$l!",
        "apply_factor": 5,
        "name" : "����",
        "damage_type": "����"
]),

([      "action": "$NͻȻ����$n,˫�ֲ�ס�ؿ칥������������$n��$l��",
        "apply_factor": 5,
        "name" : "����",
        "damage_type": "����"
]),

([  "action": "$N���ֳ�$n������ץȥ������ȴͻȻ�����ֽ������������$n��$l!",
        "apply_factor": 5,
        "name" : "����",
        "damage_type": "����"
]),

});


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ̫����֡�\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ[̫�����]!\n");
     return 1;
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

