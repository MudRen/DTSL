

#include <ansi.h>

inherit SKILL;

int valid_learn(object me)  
{

        int i = (int)me->query_skill("force", 1);
        if (i>400) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
        return 1;
}


string exert_function_file(string func)
{
        return "/daemon/skill/force/" + func;
}

string *query_exert()
{
	return ({"jing","qi","shen","heal"});
}

string query_type()
{
	return "base";
}
