//�Ե�

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N���е�$w����һ���磬�д��ŷ���֮��һ�С�����ŭ�𡹳�$n��$l����ȥ��",
    "apply_factor": 3,
    "name": "����ŭ��",
    "damage_type":"����",
  ]),
 ([ "action":"$N����$wһ������ʽ�仺���ľߵ���֮ʽ��һ�С��������졹��$n��$l��նȥ��",
    "apply_factor": 10,
    "name": "��������",
    "damage_type":"����",
  ]),
  ([ "action":"$N������$w֮�ϣ�����һ�ӣ�����ƴ�����һ�С���������������$n��",
    "apply_factor": 5,
    "name": "��������",
    "damage_type":"����",
  ]),
  ([ "action":"$N����$w��ͬ���Ǳ��꣬����ͣЪ�س�$n��ȥ������һ�С������������",
    "apply_factor": 7,
    "name": "�������",
    "damage_type":"����",
  ]),
 });   

string *parry_weapon=({

"$N���������е�$w������һ�ɰ�����һ�и���$n��$v��\n",
"$N����$w���һ��������������һ����һ��ʮ���ε��⽫$n��$v�������棡\n",
"$N˿��Ҳ�����ã����е�$w���������������ȵ�$n���������е�$v��\n",
"$N����$wһ�ӣ�ǿ������ʽ��$n���һ����$v�Ľ�������̼䱻�����һ�ɶ�����\n"

});

string *parry_hand=({

"$N���һ�������е�$w��$n��������ȥ��$n���һ������æ�����˽�����������\n",
"$N���˷��أ����е�$w��ֱ��$n��ͷ����ȥ��$n��$N����ƴ�������������Լ��Ľ����Ѿ�ȫ��������\n",
"$Nһ�����е�$w��$nֻ����һ�����������������æ���ؽ�����������\n",
"$Nһ����Ц�����е�$w��Ȼ��һ�з�ס��$n�Ľ�������������֮�ʣ�\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

int valid_learn(object me)
{

        int i = (int)me->query_skill("badao", 1);
     object weapon;

        if (i>=200) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ���ϰ�ˡ� \n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
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


mapping query_action(object me, object weapon)
{
   mapping act;
   act=action[random(sizeof(action))];
   return act;

}

mapping *query_all_action(object me)
{
return action;	
}

string *query_perform()
{
	return ({"zongheng"});
}
string query_type()
{
	return "blade";
}
string query_base()
{
	return "blade";
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}


int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/badao"))
  return 200;
  return 100;
}
