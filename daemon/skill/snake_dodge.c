// �˲��ϲ�

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n�͵�һ�����㿪��$N�Ĺ�����" ,
	    "dodge"  : 30
]),
([      "action" : "$n���һ�ܣ�������$N�Ĺ�����" ,
	    "dodge"  : 25
]),

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