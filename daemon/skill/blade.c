// 

inherit SKILL;


string query_type()
{
	return "base";
}


string perform_action_file(string action)
{
	return __DIR__"blade/"+action;
}

int valid_learn(object me)  
{

        int i = (int)me->query_skill("blade", 1);
        if (i>400) return notify_fail("学就只能学的这里了，剩下的要靠你自己领悟了。 \n");
        return 1;
}
