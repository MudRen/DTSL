// �˲��ϲ�
//NPC skills

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$nһ��[����׷��]�㿪��$N�Ĺ�����"
]),
([      "action" : "$n���в�ס�ػζ�,һ��[�����Ӱ]�㿪��$N�Ĺ�ʽ��"
]),
([      "action" : "$næʹ��һ��[���̤��],���˿���!"
]),
([      "action" : "$n�������,һ��[��������]Խ����$N��ͷ����"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}



string query_type()
{
	return "base";
}

string query_base()
{
	return "dodge";
}


int valid_learn(object me)  
{

        int i = (int)me->query_skill("babu-ganchan", 1);
        if (i>=400) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
        return 1;
}

int query_dodge(object me)
{
	return 20;
}
