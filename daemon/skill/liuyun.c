//������.������Ժ�Ṧ.

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n��������,����������,����һ��,һ��[���ƶ���]�㿪��$N�Ĺ�����"
]),
([      "action" : "$n��׼$N��λ��,�������֮�еİ���Ʈ��һ��,����һ��[�����޳�]��"
]),
([      "action" : "$n��������,����ֻ��΢΢һ��,��������$N�Ĺ���,����һ��[��������]!"
]),
([      "action" : "$n���������һ�,�㿪��$N�Ĺ���,��ͬ������Ӱһ��,����һ��[�����޳�]��"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
       if((int)me->query("PKS",1)>=5)
		   return notify_fail("��ɱ��̫��,���ܼ���ѧϰ[������]��!\n");

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