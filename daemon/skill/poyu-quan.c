// ����ȭ���μұ��书��
// �͵ȼ�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N��ȭ�·�����ȭ�͵ػӳ���һ�С����ż�ɽ������$n��$l!",
        "apply_factor": 2,
        "name" : "���ż�ɽ",
       "damage_type": "����"
]),

([  "action": "$N���в�ס�仯����ȭ�������һ�£���ȭ���͵ػӳ���һ�С���������������$n��$l!",
        "apply_factor": 3,
        "name" : "��������",
        "damage_type": "����"
]),

([      "action": "$N˫ȭ���һƬȭӰ��һ�С����Ǳ��꡹����$n��$l����",
        "apply_factor": 4,
        "name" : "���Ǳ���",
        "damage_type": "����"
]),

([  "action": "$N˫ȭʮ�ֽ��棬���ؼ汸��һ����Х��һ�С�����ʮ�֡�����$n��$l!",
        "apply_factor": 5,
        "name" : "����ʮ��",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"ֻ��$N����$n��$v����ס��$n������ͬʱ������ǰһײ��$n���ò����˿�����\n",
"$N��ȫ����$n��$v�������Ը�����ٶȴ���$n��$l������Χκ���԰㻯����$n�Ľ�����\n",
"$N˫ȭʮ�ֽ��棬���ؼ汸����ס��$n�Ľ�����\n",
"$N˫ȭ���һƬȭӰ��������$n�Ľ�����\n"

});

string *parry_hand=({

"$N������ӭ��$n�Ľ�����ֻ������һ����˫�����˺󼸲���\n",
"$Nȭ�����ң���ͬ��ǧ��Ӱ��$n���Ʋ��ã���æ���˿�����\n",
"$N��ʽ�Ͻ�������˿�����ң�����һ�л�����$n�Ľ�����\n",
"$N��ȭ������һ����������$n�Ľ�����\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}

mapping *query_all_action(object me)
{
return action;	
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ����ȭ��\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ����ȭ��\n");
     return 1;
}

string query_type() 
{
	return "hand";
}

string query_base()
{
	return "cuff";
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
