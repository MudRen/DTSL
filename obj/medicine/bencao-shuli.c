
inherit SKILL;

int valid_learn(object me)
{
	if(me->query_skill("poison",1))
	return notify_fail("��ѧ�˶���������ѧϰ��������\n");
	
	return 1;
}

string query_type()
{
	return "literate";
}
