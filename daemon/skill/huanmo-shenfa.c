//��ħ�����������Ṧ��

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n���������һΣ���������֮����һ��[�������]���ɵض㿪$N�Ľ�����"
]),
([      "action" : "$n����һ�����̣�Ʈ��������������ĥ������һ��[��ħ����]������$N�����"
]),
([      "action" : "$n��̬����֮��������֮��˿�������Ǳ�̬֮��һ��[�貨����]�ܿ���$N�Ĺ�����!"
]),
([      "action" : "$n����ͻȻ�������£����������еĻ��飬һ��[����ػ�]�㿪��$N�Ĺ�����"
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
	return 100;
}