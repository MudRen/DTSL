//�����м�.

#include <ansi.h>
inherit SKILL;

int valid_learn(object me)  
{

        int i = (int)me->query_skill("parry", 1);
        if (i>400) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
        return 1;
}

string query_type()
{
return "base";
}
