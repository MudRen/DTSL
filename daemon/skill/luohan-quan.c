// �޺�ȭ��������Ժ��
// �͵ȼ�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N�����Ͻ��������������ɣ��͵�һʽ������ʽ������$n��$l��",
        "apply_factor": 2,
        "name" : "����ʽ",
       "damage_type": "����"
]),

([  "action": "$N˫ȭ�������磬�����೯$n��$l������������һ�С�����ʽ����",
        "apply_factor": 3,
        "name" : "����ʽ",
        "damage_type": "����"
]),

([      "action": "$N���κ��ˣ�˿�����ң����д����س�$n��$l����ȥ������һ�С�����ʽ����",
        "apply_factor": 4,
        "name" : "����ʽ",
        "damage_type": "����"
]),

([  "action": "$N�͵�����$n��˫ȭ�ɿ������ͻȻһ�С���ħʽ������$n��$l����",
        "apply_factor": 5,
        "name" : "��ħʽ",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N����ע��$n��$v����׼���ᣬһ�´���$v�ı�Ե������$n��$v��\n",
"$N��׼ʱ����˫ȭһ��$n�����󣬻�����$v�Ľ�����\n",
"$Nһ��ͷ�����γ��Ա�һ����һ��$v�����󣬱ܿ���$n�Ľ�����\n",
"$N����������һ����������$n�Ľ�����\n"

});

string *parry_hand=({

"$N��˫ȭӭ��$n�Ľ�����ֻ������һ����˫�����˺󼸲���\n",
"$Nȭ���Ͻ���˿����©������$n���Ʋ��ã���æ���˿�����\n",
"$N�ͺ�һ����˫ȭһ̧����ס��$n�Ľ�����\n",
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
      
      if(me->query("PKS")>=5)
      return notify_fail("��е��������أ��޷�����ѧϰ��ȥ��\n");  
      
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ�޺�ȭ��\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(me->query("PKS")>=5)
      return notify_fail("��е��������أ��޷�������ϰ��ȥ��\n");  
      
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ�޺�ȭ��\n");
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
  
  return 40;
}