//�Ĺ�����


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
    if(me->query_per()<28)
    return notify_fail("�㳤����ô���˭���������Ի󰡣���\n");
    return 1;
}

string *query_perform()
{
   return ({"huanmei"});
}
