// ��������

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n����΢΢һ�Σ���������Ծ�ϸ߿գ�������$N�Ĺ�����"
]),
([      "action" : "$n���в�ס�ػζ�,ʮ�����ɵ�������$N�Ľ�����"
]),
([      "action" : "$n����ͻȻһ�ᣬ����������һ������ת�Ŷ㿪��$N�Ľ���!"
]),
([      "action" : "$n����һ�Σ���������գ������䵽��$N�����"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}



string query_type()
{
	return "dodge";
}

string query_base()
{
	return "dodge";
}

int query_dodge(object me)
{
	return 90;
}