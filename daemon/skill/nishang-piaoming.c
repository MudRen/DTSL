//����Ʈ�顣�������书��

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n�������Ա�һ�������Ӱһ�㣬һ�С���¥�ó����㿪��$N�Ľ�����"
]),
([      "action" : "$n��������һ�ݣ�������һ�㣬һ�С��˷����硹������������$N�����"
]),
([      "action" : "$n��̤�������������Σ���$N��ĥ������һ�С�����ң�ס�������$N����ߡ�"
]),
([      "action" : "$n���м������Σ�����������$N�Ľ�����һ�С��ƹ�̺�����������$N�����"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
    
	   return 1;
}



int practice_skill(object me)
{
     
	
	return 1;
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
	return 80;
}