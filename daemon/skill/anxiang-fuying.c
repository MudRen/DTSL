//���㸡Ӱ���μұ��书��

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n���к��ˣ��������磬һ�С���Ʈ�������㿪��$N�Ĺ�����"
]),
([      "action" : "$n�����͵�����Ծ��������������һ�С���Ӱ���١�������$N�����ԡ�"
]),
([      "action" : "$n�������̣�����Ʈ�죬һ�С�������Ӱ�����ɵض㿪��$N�Ĺ�����"
]),
([      "action" : "$n��̤��������������֮�������ĥ������һ�С���Ӱ�޳����㿪��$N�Ĺ�����"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{

        int i = (int)me->query_skill("anxiang-fuying", 1);
        if (i>=400) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ���ϰ�ˡ� \n");
    
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
	return 40;	
	
}
