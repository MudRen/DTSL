//���ǵ���
//�ͼ��书
inherit SKILL;
#include <ansi.h>

mapping *action=({
 ([ "action":"$N����$wһ��һ�С�������ʳ���ó����쵶Ӱ£��$n��$l��",
    "apply_factor": 2,
    "name" : "������ʳ",
    "damage_type":"����",
  ]),
  ([ "action":"$Nչ���鲽������Ծ�䣬һ�С���ҹ��Ӱ��������һ������ն��$n��",
    "apply_factor": 3,
    "name" : "��ҹ��Ӱ",
    "damage_type":"����",
  ]),
  ([ "action":"$N����$w��ʹ��һ�С�Ⱥ�Ƿ�ʬ�����������ã����ҿ�����������$n��",
    "apply_factor": 4,
    "name" : "Ⱥ�Ƿ�ʬ",
    "damage_type":"����",
  ]),
  ([ "action":"$Nʹ��һ�С�����Ϯ�¡�������һ����бб����$n��$l��",
    "apply_factor": 5,
    "name" : "����Ϯ��",
    "damage_type":"����",
  ]),

});   


string *parry_weapon=({

"$N����$wר����·����ȫ���˼��Լ��İ�ȫ���͵ؼ�ס��$n��$v��\n",
"$N��ͬƴ��һ�㣬$w��ǰһ�ܣ���ס��$n��$v��\n",
"$N�ͺ�һ��������$wһ��һ������Ȼ��ס��$n��$v��\n",
"$N����$w����һת�����һ���׹�Χס�Լ�����$n��$v�������棡\n"

});

string *parry_hand=({

"$N����$wһ�ƣ�����һ�����磬$n���ò��ջ���ʽ���˿�����\n",
"$N����Ϊ�أ�����$w������$nնȥ��$n���ò��ջ���ʽ��Ծ��㿪��\n",
"$Nһ�����ң�һ������һ��ֱ�������������Ȼ��$n�Ľ�����Ϊ���С�\n",
"$N�ӵ����һն��$n�Ľ������ɵñ�ǣ����ȥ��$n����һ������æ���˿�����\n"

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
	return "blade";
}
string query_base()  
{
	return "blade";
}

int valid_learn(object me)
{
	object weapon;
	if(!objectp(weapon=me->query_temp("weapon"))||
		weapon->query("skill_type")!="blade")
			return notify_fail("�����޵������ѧϰ���ǵ�����\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
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