//��ɳ����.
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N����$w�͵�һ�ӣ�����ƫ�棬��$n��$l����ȥ��",
    "apply_factor": 4,
    "name" : "��ɳ����",
    "damage_type":"����",
  ]),
 ([ "action":"$N����һ�����������㣬���˻��ߣ�����$n��$l��",
    "apply_factor": 4,
    "name" : "��ɳ����",
    "damage_type":"����",
  ]),
  ([ "action":"$N�������飬������£�����֮��ͻȻһ�д���$n��$l!",
    "apply_factor": 4,
    "name" : "��ɳ����",
    "damage_type":"����",
  ]),
  ([ "action":"$N������ע��$w֮�ϣ��ͺ�һ������$n��$l��ȥ��",
    "apply_factor": 4,
    "name" : "��ɳ����",
    "damage_type":"����",
  ]),
 });   


int valid_learn(object me)
{
    if((int)me->query_skill("chensha-jianfa",1) > 400 )
        return notify_fail("������ѧϰ�Ѿ��޷�����ӱ���������ˣ��Լ�ȥ������ɡ� \n");
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
string query_type()
{
	return "sword";
}
string query_base()
{
	return "sword";
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
