// dodge

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$nһ�Σ�����$N�Ĺ�����" ,
	    "dodge"  : 30
]),
([      "action" : "$nһ�������˿�����" ,
	    "dodge"  : 25
]),
([      "action" : "$n��æ���ˣ����˿���!" ,
	    "dodge"  : 30
]),
([      "action" : "$n��æ�������ܿ���$N�Ĺ�����" ,
	    "dodge"  : 40
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
    
        int i = (int)me->query_skill("dodge", 1);
        if (i>400) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
	   return 1;
}



int practice_skill(object me)
{
     
	return 1;
}

string query_type()
{
	return "base";
}

string perform_action_file(string action)
{
	return __DIR__"dodge/"+action;
}
