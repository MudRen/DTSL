// �Ľ��ɡ�
//�м���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����Ծ��һ�С���ѩ�׷ɡ���˫������ɽ����֮������$n��$l��",
        "apply_factor": 2,
        "name": "��ѩ�׷�",
       "damage_type": "����"
]),

([  "action": "$N����һ�ף�һʽ����ɨ��Ҷ��������Ϊ��,����ɨ��$n��˫�ȣ�",
        "apply_factor": 3,
        "name": "��ɨ��Ҷ",
        "damage_type": "����"
]),

([      "action": "$Nʹ��һʽ��ѩ��ƮƮ����$n�������Ѩ����˫�ȵ�����֮�¡�",
        "apply_factor": 4,
        "name": "ѩ��ƮƮ",
        "damage_type": "����"
]),

([  "action": "ֻ��$N���һ����һ�С�ѩ����졹��˫��֧�ض���,˫������$n�����ţ����ǹ����ޱȡ�",
        "apply_factor": 5,
        "name": "ѩ�����",
        "damage_type": "����"
]),

([  "action": "$Nһʽ����ת�ƻá�Ծ��$n��ǰ��˫��һ��$n��������ϥײ��$n��С����",
        "apply_factor": 6,
        "name": "��ת�ƻ�",
        "damage_type": "����"
]),

([  "action": "$Nһ�С����Ƶ�������$n����һ�ȡ���һ�ȷ·������أ�ʹ$n���޿ɵ������޿ɱܣ�",
        "apply_factor": 7,
        "name": "���Ƶ�",
        "damage_type": "����"
]),
});

string *parry_weapon=({

"$N����Ծ��˫��������$n������ȥ��$n��æ�ջ�$v�����˿�����\n",
"$N����������һɨ��һƬɳ����$n��ȥ��$nһ������æ�ջ�$v�˺󼸲���\n",
"$N��������������˫�������߳���žž�����߿���$n��$v��\n",
"$N�ҽ��߿�$n��$v������һת������ֳ�$n��ͷ����ȥ��$nһ�������ջ�$v���˿�����\n"

});

string *parry_hand=({

"$N����Ծ��˫��������$n������ȥ��$n��æ���˿�����\n",
"$N����������һɨ��һƬɳ����$n��ȥ��$nһ������æ�˺󼸲���\n",
"$N��������������˫�������߳���žž���¸���$n�Ľ�����\n",
"$N�ҽ��߿�$n�Ľ���������һת������ֳ�$n��ͷ����ȥ��$nһ���������˿�����\n"

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
     return 1;  
        
       
}

int practice_skill(object me)
{
   return 1;
}



string query_type() 
{
	return "hand";
}

string query_base()
{
	return "leg";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

string *query_perform()
{
  return ({"jifeng"});
}

int skill_damage(object me,object victim)
{

  return 100;
}

