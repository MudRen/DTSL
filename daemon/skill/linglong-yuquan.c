// ������ȭ.������
// �ڶ��ȼ��书��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����̬���ţ������������ң���������һ������ȭһ�С�ӭ�Űݿ͡�����$n��$l!",
        "apply_factor": 2,
        "name" : "ӭ�Űݿ�",
       "damage_type": "����"
]),

([  "action": "$N�Ų����ǲ��������������赸����ȭ��סҪ������ȭһ�С���������������$n��$l!",
        "apply_factor": 5,
        "name" : "��������",
        "damage_type": "����"
]),

([      "action": "$N�����͵��ڿն�����ͬ�����·�һ�㣬һ�С����ӷ��ס�����$n��$l!",
        "apply_factor": 10,
        "name" : "���ӷ���",
        "damage_type": "����"
]),

([  "action": "$N��̾һ������ȭ���˸�Բ������ȭ���ƺ�������ش��������һ�С��������ġ�����$n��$l!",
        "apply_factor": 7,
        "name" : "��������",
        "damage_type": "����"
]),

});

string *parry_weapon=({

"$Nһȭ��$n��$v��ȥ��ƾ��ǿ�����������$n��$v��\n",
"$N��̬���ţ������������ң���ȭ���˸�Բ������ס��$n�Ľ�����\n",
"$N�����͵��ڿն��𣬶��������赸���㿪��$n�Ľ�����\n",
"$N��̾һ����������˫ȭ֮�ϣ�����$n��$v��\n"

});

string *parry_hand=({

"$N��˫ȭӭ��$n�Ľ�����ֻ������һ����˫�����˺󼸲���\n",
"$Nȭ�����죬����һ��ʩչ������$n���Ʋ��ã���æ���˿�����\n",
"$N����Ź֣�˫ȭ�����ݳ������û�����$n�Ľ�����\n",
"$N��$n���ƶ���һ��ֻ������һ����˫�����˺󼸲���\n"

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
            return notify_fail("�����ֲ���ѧϰ������ȭ��\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("������ֲſ�����ϰ[������ȭ]!\n");
     return 1;
}

string *query_perform()
{
	return ({"mie"});   
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
  
  return 120;
}
