//���մ󷨡���ɽ�ڹ���
inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
     return 1;
}


int practice_skill(object me)
{
          return notify_fail("���մ�ֻ��ͨ��ѧ�����!\n");
}


string query_type()
{
	return "force_skill";
}

string query_base()
{
	return "force";
}

int query_exercise(object me)
{
	int level;
	level=(int)me->query_skill("huanri-dafa",1);
        return (level)/10?level/10:1;
}

int query_respirate(object me)
{
	int level;
	level=(int)me->query_skill("huanri-dafa",1);
	return level/5?level/5:1;

}

string sub_exercise(object me)
{
	int level;
	return HIC"$N"+HIC+"�������죬����"+HIW+"���մ󷨣�"+HIC+"˲��"+HIR+"��ɫ����"+HIC+"���緵�ϻ�ͯһ�㡣\n"NOR;

}

string sub_respirate(object me)
{
	int level;
	return HIC"$N"+HIC+"�������죬����"+HIW+"���մ󷨣�"+HIC+"˲��"+HIR+"��ɫ����"+HIC+"���緵�ϻ�ͯһ�㡣\n"NOR;
       
}
string *query_exert() 
{
	return ({"tuotai","huizhuan"});
}
