//�̺��񹦡�

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
    if((int)me->query_skill("bihai-force",1)>400)
        return notify_fail("������ѧϰ�Ѿ��޷�����ӱ���������ˣ��Լ�ȥ������ɡ� \n");
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("�̺���ֻ��ͨ��ѧ�����!\n");
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
	if(me->query_skill("tianmo-dafa",1))
		return notify_fail("��ֻ���������޷�ƽ���������޷�������ȥ!\n");
	level=(int)me->query_skill("dongming-xinfa");
	if(level<=50)
		return 10;
	else if(level<=120) return 15;
	else return 20;
}

int query_respirate(object me) //����ʱ����.
{
	int level;
	if(me->query_skill("tianmo-dafa",1))
		return notify_fail("��ֻ���������޷�ƽ���������޷�����������ȥ��\n");
	level=(int)me->query_skill("dongming-xinfa");
	if(level<=50)
		return -10;
	else if(level<=120) return -15;
	else return -20;

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("bihai-force",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"�������еĸ������ʹ���������ۼ��ڵ���֮�С�\n"NOR;
	else if(level<=150) return YEL"$N"+NOR+YEL+"����߾�����Ϣ�ڻ����Ѩ��ס���ߡ�\n"NOR;
	else if(level<=200) return HIC"$N"+NOR+HIC+"˫�ƽ��������ڵ���֮����Ĭ�˱̺��񹦡�\n"NOR;
	else if(level<=250) return MAG"$N"+NOR+MAG+"����һ��һ����������ɫ���罻����\n"NOR;
	else if(level<=300) return HIM"$N"+NOR+HIM+"��Ϣ�Ƴ���һ��һϢ�����಻����\n"NOR;
	else if(level<=350) return HIY"$N"+NOR+HIY+"��ɫ���ţ��������ź���֮����˫��΢������������������Х֮����\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"�����������������죬����ð��һ�ɺ�����\n"NOR;
	else return HIG"$N"+HIG+"�����һ����Ϣ��"+NOR+MAG+"�����Ѩ"+HIG+"�Ĵ����ߣ���������һ�ɺ�����\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("bihai-force",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"�������еĸ������ʹ���������ۼ��ڵ���֮�С�\n"NOR;
	else if(level<=150) return YEL"$N"+NOR+YEL+"����߾�����Ϣ�ڻ����Ѩ��ס���ߡ�\n"NOR;
	else if(level<=200) return HIC"$N"+NOR+HIC+"˫�ƽ��������ڵ���֮����Ĭ�˱̺��񹦡�\n"NOR;
	else if(level<=250) return MAG"$N"+NOR+MAG+"����һ��һ����������ɫ���罻����\n"NOR;
	else if(level<=300) return HIM"$N"+NOR+HIM+"��Ϣ�Ƴ���һ��һϢ�����಻����\n"NOR;
	else if(level<=350) return HIY"$N"+NOR+HIY+"��ɫ���ţ��������ź���֮����˫��΢������������������Х֮����\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"�����������������죬����ð��һ�ɺ�����\n"NOR;
	else return HIG"$N"+HIG+"�����һ����Ϣ��"+NOR+MAG+"�����Ѩ"+HIG+"�Ĵ����ߣ���������һ�ɺ�����\n"NOR;
}

string *query_exert() 
{
	return ({"shui","huo"});
}



