//��Ԫ����(force)

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
      
      return 1;
}


int practice_skill(object me)
{
          return notify_fail("��Ԫ����ֻ��ͨ��ѧ�����!\n");
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
	return 1;
}

int query_respirate(object me) 
{
	return 1;

}

string sub_exercise(object me)
{
	
	return "$N��ϥ���£���������������\n";
	
}

string sub_respirate(object me)
{
	return "$N��ϥ���£������¹����¡�\n";
}
