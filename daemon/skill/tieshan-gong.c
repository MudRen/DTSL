//���ȹ���
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N����$wһ�Σ����廮�˸����ߣ���$n��$l����ȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
 ([ "action":"$N����������$w֮�ϣ�������$n��$l����ȥ!",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N��������һ�Σ��ȴ����ֻ������֣��͵س�$n��$l����ȥ��",
    "apply_factor": 5,
    "name" : "����",
    "damage_type":"����",
  ]),
  ([ "action":"$N����$wһ�ţ���ס��$n�Ľ�����ͬʱ$wһ��˳�Ʒ�����ȥ��",
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
