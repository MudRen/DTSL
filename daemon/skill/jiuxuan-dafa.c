//������(force)

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
      
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
	int level;
	level=me->query_skill("jiuxuan-dafa",1);
	if(level<5) return 1;
	return level/5<100?level/5:10;
}

int query_respirate(object me) 
{
	int level;
	level=me->query_skill("jiuxuan-dafa",1);
	if(level<7) return 1;
	return level/7<100?level/7:30;

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("jiuxuan-dafa",1);
	if(level<=100) return WHT"$N"+NOR+WHT+"�ų�һ�������ϥ��������������������\n"NOR;
	else if(level<=150) return HIG"$N"+NOR+HIG+"�ֽźͺϿ���������������������\n"NOR;
	else if(level<=200) return HIW"$N"+NOR+HIW+"��Ϣ�������������������ִ�������֮�ϣ�����ǰ"+HIY+"���˸�������"+NOR+HIW+"������Ϣ���߸���������\n"NOR;
	else if(level<=250) return YEL"$N"+NOR+YEL+"˫�ַ���ϥ�ϣ�ʳָ���������������֮����\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"��������Ĭ�˾����󷨣�����Ϣ���������˾Ÿ����졣\n"NOR;
	else if(level<=350) return HIC"$N"+NOR+HIC+"���󽣾��������ƺ��Ѿ�����һ�塣\n"NOR;
	else if(level<=400) return HIM"$N"+NOR+HIM+"˫����Ȼ�ش���ϥ�ϣ�����͸����������\n"NOR;
	else return MAG"$N"+NOR+MAG+"�ֽźͺϿ�������"+HIY+"��ɫ��Ȼ��"+NOR+MAG+"�Ѿ�������Ȼ֮�С�\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("jiuxuan-dafa",1);
	if(level<=100) return WHT"$N"+NOR+WHT+"�ų�һ�������ϥ��������������������\n"NOR;
	else if(level<=150) return HIG"$N"+NOR+HIG+"�ֽźͺϿ���������������������\n"NOR;
	else if(level<=200) return HIW"$N"+NOR+HIW+"��Ϣ�������������������ִ�������֮�ϣ�����ǰ"+HIY+"���˸�������"+NOR+HIW+"������Ϣ���߸���������\n"NOR;
	else if(level<=250) return YEL"$N"+NOR+YEL+"˫�ַ���ϥ�ϣ�ʳָ���������������֮����\n"NOR;
	else if(level<=300) return HIY"$N"+NOR+HIY+"��������Ĭ�˾����󷨣�����Ϣ���������˾Ÿ����졣\n"NOR;
	else if(level<=350) return HIC"$N"+NOR+HIC+"���󽣾��������ƺ��Ѿ�����һ�塣\n"NOR;
	else if(level<=400) return HIM"$N"+NOR+HIM+"˫����Ȼ�ش���ϥ�ϣ�����͸����������\n"NOR;
	else return MAG"$N"+NOR+MAG+"�ֽźͺϿ�������"+HIY+"��ɫ��Ȼ��"+NOR+MAG+"�Ѿ�������Ȼ֮�С�\n"NOR;
}

string *query_exert() 
{
	return ({"yi","guixi"});
}
