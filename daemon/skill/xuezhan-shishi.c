//Ѫսʮʽ�����
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":HIR"$N����$wһ�ᣬ��Ȼ��һ�ɽ���֮ʽ����ס��$n��������ʽ������һ��[��������]��"NOR,
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
 ([ "action":HIR"$N����$wһ����������ǰ��$wˢ��һ�����˹�ȥ������һ��[��â��¶]��"NOR,
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":HIR"$N����һ�Σ�������$n������е�$w�͵ػӳ�������һ��[����ͻ��]��"NOR,
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":HIR"$N����$w�������£�������ǰ������$wһ��[̽��ȡ��]ֱ����$n��$l��"NOR,
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":HIR"$N����Ծ�����е�$w��ֱ���£�����һ��[һս����]����$n��$l��"NOR,
     "apply_factor": 5,
    "name" : "����",
     "damage_type":"����",
    ]),
  ([ "action":HIR"$N����$wһ�ӣ�������$n�Ľ�����ͬʱһ��[��������]��$n��$l����ȥ��"NOR,
     "apply_factor": 5,
    "name" : "����",
     "damage_type":"����",
    ]),  
   ([ "action":HIR"$N���е�$w�ķ�����������һƬ��Ӱ������һ��[���޳���]����$n��$l��"NOR,
     "apply_factor": 5,
    "name" : "����",
     "damage_type":"����",
    ]), 
   ([ "action":HIR"$N�͵ز�����ӣ����е�$wֱ�ӿ���$n��$l,����һ��[��������]��"NOR,
     "apply_factor": 5,
    "name" : "����",
     "damage_type":"����",
    ]), 
	([ "action":HIR"$N���е�$w���Ҹ񣬾���������$n�Ľ���������һ��[ǿ����֮]��"NOR,
     "apply_factor": 5,
    "name" : "����",
     "damage_type":"����",
    ]), 
	([ "action":HIR"$N���е�$w�ӳ������з���֮�������е���֮���ƣ�һ��[��������]����$n��$l��"NOR,
     "apply_factor": 5,
    "name" : "����",
     "damage_type":"����",
    ]), 
 });   


int valid_learn(object me)
{
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
   return action[random(sizeof(action))];

}

string *query_perform()
{
	return ({"bajue"});
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
