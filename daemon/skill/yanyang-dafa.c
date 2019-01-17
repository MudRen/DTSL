#include <ansi.h>
inherit FORCE;



int valid_learn(object me)
{       
   
	int i = (int)me->query_skill("yanyang-dafa", 1);
	if (i>400) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("������ֻ��ͨ��ѧ�����!\n");
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
	if(level<=100) return MAG"$N"+NOR+MAG+"�������������󷨣�һ����Ѻ������¡�\n"NOR;
	else if(level<=150) return HIM"$N"+NOR+HIM+"�淺��⣬ͷ��ð�����������\n"NOR;
	else if(level<=200) return HIG"$N"+NOR+HIG+"˫Ŀ���գ�˫����ȭ������˫ϥ֮�ϡ�\n"NOR;
	else if(level<=250) return WHT"$N"+NOR+WHT+"����֮�䣬��Ŀ���ɲ�ף�����ð�����������\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"������һ�����ˣ��������ս���һ�㡣\n"NOR;
	else if(level<=350) return HIC"$N"+NOR+HIC+"����ƽ����һ�������������ش�����ɢ��������\n"NOR;
	else if(level<=400) return RED"$N"+NOR+RED+"��ɫ����˲��ת�ף�����������������\n"NOR;
	else return HIR"$N"+NOR+HIR+"��ɫ"+HIR+"��"+HIW+"��"+HIR+"���棬��ɫ��͡�\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("yanyang-dafa",1);
	if(level<=100) return MAG"$N"+NOR+MAG+"�������������󷨣�һ����Ѻ������¡�\n"NOR;
	else if(level<=150) return HIM"$N"+NOR+HIM+"�淺��⣬ͷ��ð�����������\n"NOR;
	else if(level<=200) return HIG"$N"+NOR+HIG+"˫Ŀ���գ�˫����ȭ������˫ϥ֮�ϡ�\n"NOR;
	else if(level<=250) return WHT"$N"+NOR+WHT+"����֮�䣬��Ŀ���ɲ�ף�����ð�����������\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"������һ�����ˣ��������ս���һ�㡣\n"NOR;
	else if(level<=350) return HIC"$N"+NOR+HIC+"����ƽ����һ�������������ش�����ɢ��������\n"NOR;
	else if(level<=400) return RED"$N"+NOR+RED+"��ɫ����˲��ת�ף�����������������\n"NOR;
	else return HIR"$N"+NOR+HIR+"��ɫ"+HIR+"��"+HIW+"��"+HIR+"���棬��ɫ��͡�\n"NOR;
}
string *query_exert() 
{
	return ({"riyue","yanyang"});
}

