//������������leiting-chuifa.c
//�м�-->�ռ��书��

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$NԾ�ն���,����$wһת��һʽ�����׺䶥������һ��ǿ���ķ�������$n��",
    "apply_factor": 2,
    "name" : "���׺䶥",
    "damage_type":"����",
  ]),
 ([ "action":"$N˫��һ��һʽ��������ġ�������$w�д������װ������������������$n���˹�ȥ��",
    "apply_factor": 5,
    "name" : "�������",
    "damage_type":"����",
  ]),
  ([ "action":"$N�������飬һʽ���׶����졹����$w���Ϻ��£�����׽������ȥ·������$nһ��㱼䣬\n"+
              "��ৡ�������$n��$l��",
    "apply_factor": 10,
    "name" : "�׶�����",
    "damage_type":"����",
  ]),
  ([ "action":"$N��$w�߾ٹ��磬�����������׼$n��$l����һ�С�����ǧ����,��һ���ּ����͡�",
    "apply_factor": 7,
    "name" : "����ǧ��",
    "damage_type":"����",
  ]),
 });   

string *parry_weapon=({

"$N���һ�������е�$w��$n��$v��ȥ��$nһ��֮�£���æ�˺�����\n",
"$N��ȫ���˼�$n��$v���������е�$w����һ����$n��ȥ��$n��æ����$v�����˿�����\n",
"$N��$w������ǰ�����õ�ס$n��$v�����$n˫�۷��飡\n",
"$N��$wֱ��$n��������ȥ��$n����֮�£�ֻ���ջ���$v��\n"

});

string *parry_hand=({

"$N��$w��Ȼ������������$n��������ȥ��$n����֮��ֻ�ú��˼�����\n",
"$Nһ�����е�$w��$w��������һ�㣬����������֮�䣬$n�Ľ���֮��Ҳ��Ϊ���У�\n",
"$N���һ�������е�$w�������������������$n�Ľ�����\n",
"$N��$w����һ����������$n�Ľ�����\n"

});


string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

int valid_learn(object me)
{
     object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԡ�\n");
     return 1;  

}

int practice_skill(object me)
{
  object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
 return 1;  


}


mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];

}
mapping *query_all_action(object me)
{
return action;	
}

string *query_perform()
{
	return ({"pili","honglei"});
}
string query_type()
{
	return "hammer";
}
string query_base()
{
	return "hammer";
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
if(me->query("perform_quest/pili")) 
  return 200;
else
	return 80;
}
