//���ڷ𷨡�������Ժ
inherit SKILL;

int valid_learn(object me)
{
    if((int)me->query_skill("chanzong-fofa",1) > 400 )
        return notify_fail("������ѧϰ�Ѿ��޷�����ӱ���������ˣ��Լ�ȥ������ɡ� \n");
	if((int)me->query("PKS",1)>=5)
	return notify_fail("��е��Լ�������ɱ��̫�أ����ܼ���ѧϰ��ȥ�ˣ�\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("���ڷ�ֻ��ͨ��ѧ�����!\n");
}

string query_type()
{
	return "literate";
}

string help_action()
{
write(@LONG
    ���ڷ�

    ������Ժ�ķ𷨡�      
LONG);
return "\n";
}
