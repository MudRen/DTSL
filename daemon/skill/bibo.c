//�̲��ķ�


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
    if((int)me->query_skill("bibo",1)>400)
        return notify_fail("������ѧϰ�Ѿ��޷�����ӱ���������ˣ��Լ�ȥ������ɡ� \n");
    return 1;
}

string *query_execute()
{
   return ({"bibo"});
}
