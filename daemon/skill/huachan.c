//画禅
//花间派心法。


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
  //  if(me->query("execute_quest/busiyin",1))
  //  return notify_fail("你领会了不死印的奥秘，无法再领会画禅绝学。\n");
    return 1;
}

string *query_execute()
{
   return ({"xihua"});
}
