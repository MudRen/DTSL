//�������ƾ����Ⱥ���ի�ڹ��� qingxin-force

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
	if((int)me->query("PKS",1)>=5)
		return notify_fail("��ɱ����̫���ˣ��޷�ѧϰ�������ƾ���\n");
	if(((int)me->query_skill("wuwang-jing",1)-(int)me->query_skill("qingxin-force",1))<10)
		return notify_fail("�����������Ϊ�������޷������������ƾ��ˣ�\n");
	return 1;
}


int practice_skill(object me)
{
          return notify_fail("�������ƾ�ֻ��ͨ��ѧ�����!\n");
}


string query_type()
{
	return "force_skill";
}

string query_base()
{
	return "force";
}

int query_exercise(object me)//������ʱ���á�
{
	int level;
	level=(int)me->query_skill("qingxin-force",1);
	
	if(level<10) return 2;
	
	return (me->query_skill("force",1)/10+level/10+
               me->query_skill("wuwang-jing",1)/10)<100?
			(me->query_skill("force",1)/10+level/10+me->query_skill("wuwang-jing",1)/10):
			60;
}

int query_respirate(object me) //����ʱ����.
{
	int level;
	level=(int)me->query_skill("qingxin-force",1);
	
	if(level<10) return 2;
	
	return (me->query_skill("force",1)/10+level/10+
               me->query_skill("wuwang-jing",1)/10)<100?
				(me->query_skill("force",1)/10+level/10+me->query_skill("wuwang-jing",1)/10):
				60;

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("qingxin-force",1);
	if(level<=100) return HIC"$N"+NOR+HIC+"���������ų���������𽥽�������֮����\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"˫�Ʒ���ϥ�ϣ��������죬����һƬ���֮����\n"NOR;
	else if(level<=200) return YEL"$N"+NOR+YEL+"��ϥ���������к��������Ϣ��Ȼ��\n"NOR;
	else if(level<=250) return HIY"$N"+NOR+HIY+"�������£�Ǳ�����������������������������졣\n"NOR;
	else if(level<=300) return HIG"$N"+NOR+HIG+"˫ϥ����������һ����"+HIR+"���������ҡ�"+HIG+"��ʱ�ڼ�������ԣȫ��\n"NOR;
	else if(level<=350) return WHT"$N"+NOR+WHT+"�������˫Ŀ�������ƺ������������֣���Ȼ������֮�⡣\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"��ϥ������������ͣ��ƺ�����������һ�㡣\n"NOR;
	else return MAG"$N"+NOR+MAG+"�������£���������������ȫ���𽥱�"+HIB+"һ���ڼ�����"+NOR+MAG+"�����š�\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("qingxin-force",1);
	if(level<=100) return HIC"$N"+NOR+HIC+"���������ų���������𽥽�������֮����\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"˫�Ʒ���ϥ�ϣ��������죬����һƬ���֮����\n"NOR;
	else if(level<=200) return YEL"$N"+NOR+YEL+"��ϥ���������к��������Ϣ��Ȼ��\n"NOR;
	else if(level<=250) return HIY"$N"+NOR+HIY+"�������£�Ǳ�����������������������������졣\n"NOR;
	else if(level<=300) return HIG"$N"+NOR+HIG+"˫ϥ����������һ����"+HIR+"���������ҡ�"+HIG+"��ʱ�ڼ�������ԣȫ��\n"NOR;
	else if(level<=350) return WHT"$N"+NOR+WHT+"�������˫Ŀ�������ƺ������������֣���Ȼ������֮�⡣\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"��ϥ������������ͣ��ƺ�����������һ�㡣\n"NOR;
	else return MAG"$N"+NOR+MAG+"�������£���������������ȫ���𽥱�"+HIB+"һ���ڼ�����"+NOR+MAG+"�����š�\n"NOR;
}

string *query_exert() 
{
	return ({"qingxin"});
}



