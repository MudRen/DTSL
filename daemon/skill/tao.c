//��.

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N��ȭ�͵ش��,һ��[��籩��]����$n��$l!",
        "apply_factor": 5,
        "name" : "����",
        
        "damage_type": "����"
]),

([  "action": "$N����Ư��,˫ȭ���Ӱһ��,����һ��[����ǧ��]����$n!",
        "apply_factor": 5,
        "name" : "����",
       
        "damage_type": "����"
]),

([      "action": "$NͻȻ������ѹ,˫ȭ�͹���$n������,����һ��[����ǳ��]��",
        "apply_factor": 5,
        "name" : "����",
      
        "damage_type": "����"
]),

([  "action": "$N���һ��,ȫȻ���˷���,һ��[��������]����$n!",
        "apply_factor": 5,
        "name" : "����",
        
        "damage_type": "����"
]),

});


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}


string query_type()  
{
	return "hand";
}

string query_base()
{
	return "cuff";
}

