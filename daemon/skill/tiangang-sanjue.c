//��˾����μұ��ڹ���
inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
 
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("�������ֻ��ͨ��ѧ�����!\n");
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
	level=(int)me->query_skill("tiangang-bajue");
	if(level<=50)
		return 30;
	else if(level<=120) return 40;
	else return 50;
}

int query_respirate(object me) //����ʱ����.
{
	int level;
	level=(int)me->query_skill("tiangang-bajue");
	if(level<=50)
		return -30;
	else if(level<=120) return -40;
	else return -50;

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("tiangang-sanjue",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"����һ������Ȼ�����߻�����������õ���ů�ͣ�˵�����������\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"��Ϣ��Ȼ��ͨ������ȫ����������Χ����������\n"NOR;
	else if(level<=200) return HIM+"$N"+NOR+HIM+"��ϥ������˫�ƺϿۣ�����ð��������������\n"NOR;
	else if(level<=250) return RED"$N"+NOR+RED+"��Ϣ�೤����������͸��һ�ɰ�����\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"��ָ��£������˫ϥ֮�ϣ�һ�ɵ�������ȫ��\n"NOR;
	else if(level<=350) return MAG"$N"+NOR+MAG+"��̬���ϣ���Ϣ�Ƴ����������˲���������η�ĸо���\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"˫�ֽ��������ǰ��ֻ����Ϣ֮�䣬һ�ɵ�����Ѿ�������ȫ��\n"NOR;
	else return HIG"$N"+HIG+"������������Ϣ��"+NOR+MAG+"ȫ����"+HIG+"Ѹ�����ߣ����Ѵﵽ��Ȼ����ľ��硣\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("tiangang-sanjue",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"����һ������Ȼ�����߻�����������õ���ů�ͣ�˵�����������\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"��Ϣ��Ȼ��ͨ������ȫ����������Χ����������\n"NOR;
	else if(level<=200) return HIM+"$N"+NOR+HIM+"��ϥ������˫�ƺϿۣ�����ð��������������\n"NOR;
	else if(level<=250) return RED"$N"+NOR+RED+"��Ϣ�೤����������͸��һ�ɰ�����\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"��ָ��£������˫ϥ֮�ϣ�һ�ɵ�������ȫ��\n"NOR;
	else if(level<=350) return MAG"$N"+NOR+MAG+"��̬���ϣ���Ϣ�Ƴ����������˲���������η�ĸо���\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"˫�ֽ��������ǰ��ֻ����Ϣ֮�䣬һ�ɵ�����Ѿ�������ȫ��\n"NOR;
	else return HIG"$N"+HIG+"������������Ϣ��"+NOR+MAG+"ȫ����"+HIG+"Ѹ�����ߣ����Ѵﵽ��Ȼ����ľ��硣\n"NOR;
}

string *query_exert() 
{
	return ({"ningxin","zhanyi"});
}
