//���������Ⱥ���ի��

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : HIW"$n������������һ�㣬�����̤���ƣ�������������$N�Ľ�����"NOR
]),
([      "action" : HIG"$n����ת�˼�ת������������$N�Ľ���������˿�����Ի��ң�����֮����"NOR
]),
([      "action" : HIW"$n����΢������죬��������һ�㣬�߸�������������$N�����!" NOR
]),
([      "action" : HIW"$n��ɫ��ͣ����ƺ������ֻ����ˢ����һ������Ȼ������$N���ԡ�" NOR
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