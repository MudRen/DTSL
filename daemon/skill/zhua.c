//ץ��

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$NͻȻ���צ��ץ��$n\n",
        "dodge": 0,
        "force": 150,
		"damage":50,
        "parry" :50,
        
        "damage_type": "ץ��"
]),
([     "action": "$NͻȻ���˹�ȥ������$nһ��",
       "dodge": 10,
	   "force":10,
	   "parry":10,
	   "damage_type": "ץ��",
]),


});







mapping query_action(object me)
{
        return action[random(sizeof(action))];
}



