//����ָ
//�ͼ��书
inherit SKILL;
#include <ansi.h>

mapping *action=({
 ([ "action":"$N��ָһתһ��һ�С�������ʳ���ó�����ָӰ����$n��$l��",
    "apply_factor": 2,
    "name" : "������ʳ",
    "damage_type":"����",
  ]),
  ([ "action":"$Nչ���鲽������Ծ�䣬һ�С���ҹ��Ӱ������ָһת����������$n��",
    "apply_factor": 3,
    "name" : "��ҹ��Ӱ",
    "damage_type":"����",
  ]),
  ([ "action":"$N��ָ�ֵ㣬ʹ��һ�С�Ⱥ�Ƿ�ʬ�����ϴ��»������ҿ����������$n��",
    "apply_factor": 4,
    "name" : "Ⱥ�Ƿ�ʬ",
    "damage_type":"����",
  ]),
  ([ "action":"$Nʹ��һ�С�����Ϯ�¡�����ָ��ס�任��бб����$n��$l��",
    "apply_factor": 5,
    "name" : "����Ϯ��",
    "damage_type":"����",
  ]),

});   


string *parry_weapon=({

"$Nר����·����ȫ���˼��Լ��İ�ȫ��ƴ������ָ������$n��$v��\n",
"$N��ͬƴ��һ�㣬��ָ��ǰһ�̣��Թ����ر�����$n��$v��\n",
"$N�ͺ�һ������ָһ��һ������Ȼ������$n��$v��\n",
"$N��ָ����һת������ָӰΧס�Լ�����$n��$v�������棡\n"

});

string *parry_hand=({

"$N��ָ�Ӷ�������һ�����磬$n���ò��ջ���ʽ���˿�����\n",
"$N����Ϊ�أ���ָ��$n��ȥ��$n���ò��ջ���ʽ��Ծ��㿪��\n",
"$Nһָ���ң�һָ����һֱָ�̣�������ָ��Ȼ��$n�Ľ�����Ϊ���С�\n",
"$N��ָ���һ����$n�Ľ������ɵñ�ǣ����ȥ��$n����һ������æ���˿�����\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}



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
	return "hand";
}
string query_base()  
{
	return "finger";
}

int valid_learn(object me)
{
	object weapon;
	if(objectp(weapon=me->query_temp("weapon")))
			return notify_fail("�������ű��������ѧϰ����ָ����\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;
	if(objectp(weapon=me->query_temp("weapon")))
			return notify_fail("�������ű����������ϰ����ָ����\n");
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
  
  return 50;
}