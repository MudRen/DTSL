//����
//�������ķ���


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
  //  if(me->query("execute_quest/busiyin",1))
  //  return notify_fail("������˲���ӡ�İ��أ��޷�����ử����ѧ��\n");
    return 1;
}

string *query_execute()
{
   return ({"xihua"});
}
