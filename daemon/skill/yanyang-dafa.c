#include <ansi.h>
inherit FORCE;



int valid_learn(object me)
{       
   
	int i = (int)me->query_skill("yanyang-dafa", 1);
	if (i>400) return notify_fail("学就只能学的这里了，剩下的要靠你自己领悟了。 \n");
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("炎阳大法只能通过学来提高!\n");
}


string query_type()
{
	return "force_skill";
}

string query_base()
{
	return "force";
}

int query_exercise(object me)
{
	if(me->query_skill("yanyang-dafa",1)<3) return 1;
	return me->query_skill("yanyang-dafa",1)/3<100?me->query_skill("yanyang-dafa",1)/3:90;
}

int query_respirate(object me) 
{
	if(me->query_skill("yanyang-dafa",1)<3) return -1;
	return -(me->query_skill("yanyang-dafa",1)/3<100?me->query_skill("yanyang-dafa",1)/3:30);


}
string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("yanyang-dafa",1);
	if(level<=100) return MAG"$N"+NOR+MAG+"缓缓运起炎阳大法，一会便已汗如雨下。\n"NOR;
	else if(level<=150) return HIM"$N"+NOR+HIM+"面泛红光，头上冒出阵阵白气。\n"NOR;
	else if(level<=200) return HIG"$N"+NOR+HIG+"双目紧闭，双手握拳，放于双膝之上。\n"NOR;
	else if(level<=250) return WHT"$N"+NOR+WHT+"呼吸之间，面目变的刹白，周身冒出阵阵白气。\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"周身发出一股热浪，好象烈日骄阳一般。\n"NOR;
	else if(level<=350) return HIC"$N"+NOR+HIC+"呼吸平缓，一阵阵热气慢慢地从身体散发出来。\n"NOR;
	else if(level<=400) return RED"$N"+NOR+RED+"面色红润，瞬间转白，周身被热气所包裹。\n"NOR;
	else return HIR"$N"+NOR+HIR+"脸色"+HIR+"红"+HIW+"白"+HIR+"交替，面色祥和。\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("yanyang-dafa",1);
	if(level<=100) return MAG"$N"+NOR+MAG+"缓缓运起炎阳大法，一会便已汗如雨下。\n"NOR;
	else if(level<=150) return HIM"$N"+NOR+HIM+"面泛红光，头上冒出阵阵白气。\n"NOR;
	else if(level<=200) return HIG"$N"+NOR+HIG+"双目紧闭，双手握拳，放于双膝之上。\n"NOR;
	else if(level<=250) return WHT"$N"+NOR+WHT+"呼吸之间，面目变的刹白，周身冒出阵阵白气。\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"周身发出一股热浪，好象烈日骄阳一般。\n"NOR;
	else if(level<=350) return HIC"$N"+NOR+HIC+"呼吸平缓，一阵阵热气慢慢地从身体散发出来。\n"NOR;
	else if(level<=400) return RED"$N"+NOR+RED+"面色红润，瞬间转白，周身被热气所包裹。\n"NOR;
	else return HIR"$N"+NOR+HIR+"脸色"+HIR+"红"+HIW+"白"+HIR+"交替，面色祥和。\n"NOR;
}
string *query_exert() 
{
	return ({"riyue","yanyang"});
}

