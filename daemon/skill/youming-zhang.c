// �����ơ����°Ե��Ʒ���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": HIB"$N���й��죬������$n�����ܣ��͵�ʹ��һ��[�Ļ�����]����$n��$l!"NOR,
        "apply_factor": 5,
        "name" : "����",
       "damage_type": "����"
]),

([  "action": HIB"$N����������������$n��ĥ������$NͻȻ������Ȱ�ʹ��һ��[ͻ�ֹ�Ӱ]����$n��$l��"NOR,
        "apply_factor": 5,
        "name" : "����",
        "damage_type": "����"
]),

([      "action": HIB"$N���Ϻ������֣���$n���ö���һ�ͣ�$N�͵�һ��[��Ц����]����$n��$l��"NOR,
        "apply_factor": 5,
        "name" : "����",
        "damage_type": "����"
]),

([  "action": HIB"$N����˫�Ʒַɣ���ͬ����һ�㣬һ��[�������]����$n��$l��"NOR,
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
     	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ�����ơ�\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ[������]!\n");
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

