//�����Ʒ���
//�͵ȼ�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����̽����ֻ��һ������һ�С����·��桹����$n��$l��",
        "apply_factor": 2,
        "name" : "���·���",
       "damage_type": "����"
]),

([  "action": "$N�ƻ���ʽ����$nֻ���ú������棬һ�С�����𡹿���$n��$l����",
        "apply_factor": 3,
        "name" : "�����",
        "damage_type": "����"
]),

([      "action": "$N����ͻȻ��죬�ķ��������͵�һ�С���Ӱ���ơ�����$n��$l��",
        "apply_factor": 4,
        "name" : "��Ӱ����",
        "damage_type": "����"
]),

([  "action": "$N��������$n��ͻȻ�����͵�һת���Ƶ�$n�������һ�С��»��������$l���˹�ȥ��",
        "apply_factor": 5,
        "name" : "�»����",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$N��̬���ţ����ƻ���һ������˼��Ĺ켣��������$n��$v��$n����һ����\n",
"$N�����ƾ�Ȼ��$n��$vӭȥ���Ӵ���ɲ�ǣ������ƺ�������ճ����������$n��$v��\n",
"$Nһ��ͷ�����γ��Ա�һ����һ��$v�����󣬱ܿ���$n�Ľ�����\n",
"$N����������һ����������$n�Ľ�����\n"

});

string *parry_hand=({

"$N��˫��ӭ��$n�Ľ�����ֻ������һ����˫�����˺󼸲���\n",
"$N�Ʒ��Ͻ���˿����©������$n���Ʋ��ã���æ���˿�����\n",
"$N�ͺ�һ����˫��һ�ӣ���ס��$n�Ľ�����\n",
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
    
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����ֲ���ѧϰ�����Ʒ���\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ�����Ʒ���\n");
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
