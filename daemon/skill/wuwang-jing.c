//������


inherit SKILL;

string query_type()
{
   return "literate";
}

int valid_learn(object me)
{
    if((int)me->query("PKS",1)>=5)
    return notify_fail("��ɱ����̫���ˣ��޷�ѧϰ��������\n");
    
    return 1;
}

string *query_execute()
{
   return ({"wuwang","po"});
}

