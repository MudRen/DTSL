//��������

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n���κ������������Ա�һ�����㿪��$N�Ľ�����"
]),
([      "action" : "$n����������岻ס��ת��һʽ���������졹�㿪��$N�Ĺ�����"
]),
([      "action" : "$n���͵�һ��أ�����ƬƬ������˳ʽһ�С�����Ϸˮ������$N�Ľ���!"
]),
([      "action" : "$n���岻ס��������$Nͷ���ӹ�������һ�С����ξ��졹��"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
    
        int i = (int)me->query_skill("youlong-shenfa", 1);
        if (i>199) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ���ϰ�ˡ� \n");
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

string *query_perform()
{
   return ({"qunxiao"});
}

int query_dodge(object me)
{
	return 30;
}
