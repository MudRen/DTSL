// �������.������


#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N������Ʈ����������ͬ��Ӱһ�㣬������$n�����һ�С���Ӱ���١�����$n��$l!",
        "apply_factor": 2,
        "name" : "��Ӱ����",
       "damage_type": "����"
]),

([  "action": "$N˫����ͬ����һ�㣬���ſ���������һ�С�����̽Ӱ��������$n��$l!",
        "apply_factor": 3,
        "name" : "����̽Ӱ",
        "damage_type": "����"
]),

([      "action": "$N��������$n����ת������Ȼ���ƣ�����һ�С�������ơ�����$n��$l!",
        "apply_factor": 4,
        "name" : "�������",
        "damage_type": "����"
]),

([  "action": "$N˫�����·��ɣ���ͬ������ǧ������ƣ�����һ�С�������á�����$n��$l��!",
        "apply_factor": 5,
        "name" : "�������",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"ֻ��$N����$n��$v����ס��$n������ͬʱ������ǰһײ��$n���ò����˿�����\n",
"$N��ȫ����$n��$v�������Ը�����ٶȴ���$n��$l������Χκ���԰㻯����$n�Ľ�����\n",
"$N˫����ͬ����һ�㣬���ſ�������ס��$n�Ľ�����\n",
"$N����������һ����������$n�Ľ�����\n"

});

string *parry_hand=({

"$N������ӭ��$n�Ľ�����ֻ������һ����˫�����˺󼸲���\n",
"$N�Ʒ����ң���ͬ��ǧ��Ӱ��$n���Ʋ��ã���æ���˿�����\n",
"$N˫�ƹ���һ��������͵�ץ��$n������$n��æ���ˣ�����һ���亹��\n",
"$N����������һ����������$n�Ľ�����\n"

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
            return notify_fail("�����ֲ���ѧϰ������ơ�\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ������ơ�\n");
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
int skill_damage(object me,object victim)
{
  
  return 40;
}
