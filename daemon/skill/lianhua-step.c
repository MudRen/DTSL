//����������������Ժ�Ṧ.

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n�������У����������ƣ�����һ�Σ�һ�С����ƶ��졹�㿪��$N�Ĺ�����"
]),
([      "action" : "$n��׼$N��λ�ã��������֮�еİ���Ʈ��һ�ԣ�����һ�С������޳�����"
]),
([      "action" : "$n�������У�����ֻ��΢΢һ��,��������$N�Ĺ��ƣ�����һ�С��������ơ���"
]),
([      "action" : "$n���������һΣ��㿪��$N�Ĺ�������ͬ������Ӱһ�㣬����һ�С������޳�����"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
       if((int)me->query("PKS",1)>=5)
		   return notify_fail("��е������������أ����ܼ���ѧϰ�������������ˣ�\n");

	   return 1;
}



int practice_skill(object me)
{
     if((int)me->query("PKS",1)>=5)
     return notify_fail("��е������������أ����ܼ�����ϰ�������������ˣ�\n");
	
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
	
	return 70;
	
}