//ץ����

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$NĿ����������������˿����ͣ����$n��$l��ץ�˹�ȥ!",
        "dodge": 20,
        "force": 60,
        "parry" : 40,
        "damage_type": "ץ��"
]),

([  "action": "$N���������ƣ����$n�˺����������ƽ����ų�$n��$l����ȥ!",
        "dodge": 30,
        "force": 60,
        "parry" : 40,
        "damage_type": "����"
]),

([      "action": "$N˫��ƽ�ƣ�ֻ��һ�ɾ޴��������$nײȥ��",
        "dodge": 20,
        "force": 60,
        "parry" : 40,
        "damage_type": "����"
]),

([  "action": "$N����ͻȻ�����������͵س�$n��$l��ץȥ!",
        "dodge": 30,
        "force": 60,
        "parry" : 40,      
        "damage_type": "ץ��"
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
	return "strike";
}

