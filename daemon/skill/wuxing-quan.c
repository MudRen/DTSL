// ����ȭ.

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$Nվ����,һ��[���ż�ɽ]����$n��$l!",
        "dodge": 0,//�������Ĺ�������
        "force": 60,//���������˺�����force+parry=100.
        "parry" : 40,//�������ķ�������
        
        "damage_type": "����"//���к���˺����͡�
]),

([  "action": "$N�����¶�,һ��[����Ҷ]ɨ��$n������!",
        "dodge": -5,
        "force": 60,
        "parry" : 40,
       
        "damage_type": "����"
]),

([      "action": "$N�͵�˫ȭ����$n��$l��,����һ��[˫������]��",
        "dodge": 0,
        "force": 60,
        "parry" : 40,
      
        "damage_type": "����"
]),

([  "action": "$NͻȻ˫ȭ��������,����һ��[��������],����$n��$l��!",
        "dodge": -5,
        "force": 60,
        "parry" : 40,
        
        "damage_type": "����"
]),

});


mapping query_action(object me)  //������������
{
        return action[random(sizeof(action))];
}


string query_type()  //�������͡�ֻҪ���Ǳ������书�������ﶼ����Ϊhand.
{
	return "hand";
}

string query_base()//���ػ����书���͡�
{
	return "cuff";
}

