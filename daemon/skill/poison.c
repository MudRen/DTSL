//基本毒术


inherit SKILL;

string query_type()
{
  return "knowledge";
}

int valid_learn(object me)
{
   if(me->query_skill("poison",1)>=me->query("int")*6)
	return notify_fail("你无法再通过学来提高此技能了，还是到实践中去提高吧！\n");
  return 1;
}