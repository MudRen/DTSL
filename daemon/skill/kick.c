//�ߡ�

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$NͻȻ�����������$n",
        "dodge": 10,
        "force": 50,
		"damage":50,
        "parry" :50,
        
        "damage_type": "����"
]),
([     "action": "$NͻȻ���˹�ȥ������$nһ��",
       "dodge": 10,
	   "force":10,
	   "parry":10,
	   "damage_type": "����",
]),


});







mapping query_action(object me)
{
        return action[random(sizeof(action))];
}



