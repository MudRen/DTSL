//�ٻ��ơ��������书��
//�м���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N˫�Ʒַɣ����β�ס��������һ�С���������������$n��$l��",
        "apply_factor": 2,
        "name" : "��������",
       "damage_type": "����"
]),

([  "action": "$N������һ����������һ̧�����绤����̬������Ѹ�ݵ�����$n,����һ�С��ĺɱ�Ӱ����",
        "apply_factor": 3,
        "name" : "�ĺɱ�Ӱ",
        "damage_type": "����"
]),

([      "action": "$N��ͻȻ������˫�ƻ�סȫ��ͬʱһ��ת��һ�С����ӭ������$n���˹�ȥ��",
        "apply_factor": 4,
        "name" : "���ӭ��",
        "damage_type": "����"
]),

([  "action": "$N��Ȼ������ǧ��Ӱ��˫������������������һ�С���÷��ѩ����$n��$l����ȥ��",
        "apply_factor": 5,
        "name" : "��÷��ѩ",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N�������·��ɣ��������γ�һ����ת��������$n��$v�������ϻ��˿�����\n",
"$N���ƶ������ᣬ���縧Ħ�ʻ�һ�㣬ƾ��������֮��ж����$n��$v��\n",
"$N����һ�����������һ���������������ϣ����ü�ס��$n������\n",
"����$n��$v����֮�ʣ�$N������һ��������ͬƮ��Ļ��꣬���˿�����\n"

});

string *parry_hand=({

"$N������ǰһ�죬��ͬ����һ���ʻ����͵���ָ΢������������֮�䣬������$n�Ľ�����\n",
"$N��æʩչ��һ�л�ͷ����֮�ƣ������������������ü�ס��$n�Ľ�����\n",
"$N����΢΢һ�ݣ�˫����ǰ���ƣ������ųɻ�����״����ס��$n�Ĺ��ơ�\n",
"$N���ƻ�ס�ؿڣ�����৵��������ͬ�֦ͻ�֣�$n����һ������æ���ƺ��ˣ�\n"

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
        if((int)me->query_skill("baihua-zhang",1)>400)
            return notify_fail("������ѧϰ�Ѿ��޷�����ӱ���������ˣ��Լ�ȥ������ɡ� \n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ�ٻ��ơ�\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ�ٻ���!\n");
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

string *query_perform()
{
  return ({"baihua"});
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  
  return 120;
}
