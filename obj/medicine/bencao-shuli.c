
inherit SKILL;

int valid_learn(object me)
{
	if(me->query_skill("poison",1))
	return notify_fail("你学了毒术，不能学习本草术理！\n");
	
	return 1;
}

string query_type()
{
	return "literate";
}
