//�����񹦡�������Ժ

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
	if ((int)me->query_skill("wuxiang-shengong",1)>400) 
    	return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
	if((int)me->query("PKS",1)>=5)
		return notify_fail("��е��������أ��޷�ѧϰ���ڹ���\n");
	if(((int)me->query_skill("chanzong-fofa",1)-(int)me->query_skill("wuxiang-shengong",1))<=10)
        return notify_fail("���Ȼ�����Լ���������ö������飬�����б�Ҫ��ϰ���ڷ��ˣ�\n");
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

int query_exercise(object me)//������ʱ���á�
{
	int level,level2;
	level=0;level2=0;
	
	if(me->query_skill("tianmo-dafa",1))
		return notify_fail("��ֻ�����������й�а��������,�����ڼ���������ȥ!\n");
	level=(int)me->query_skill("wuxiang-shengong",1);
	if(me->query_skill("changsheng-jue",1)) 
		level2=me->query_skill("changsheng-jue",1);
    if(level&&level2){
		if((level/2+level2)<50) return 20;
        if((level/2+level2)<120) return 30;
		return 45;
	}
	else{
		if(level<50) return 15;
		if(level<120) return 20;
		return 25;
	}
}

int query_respirate(object me) //����ʱ����.
{
	int level,level2;
	level=0;level2=0;
	
	if(me->query_skill("tianmo-dafa",1))
		return notify_fail("��ֻ�����������й�а��������,�����ڼ���������ȥ!\n");
	level=(int)me->query_skill("wuxiang-shengong",1);
	level2=me->query_skill("changsheng-jue",1);
	if(level&&level2){
		if((level/2+level2)<50) return 0;
        if((level/2+level2)<120) return 10;
		return 15;
	}
	else{
		if(level<=50)
			return -10;
		else if(level<=120) return -15;
		else return -20;
	}

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("wuxiang-shengong",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"�������������񹦣��������ڵ����������������\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"������Ϣ��ֻ�����������������˵�����������\n"NOR;
	else if(level<=200) return MAG"$N"+NOR+MAG+"����������ϥ����������������"+HIB+"�������Ҿ��磬"+NOR+MAG+"һ�����ȵ���Ϣ���ζ�����֮�����ߡ�\n"NOR;
	else if(level<=250) return YEL"$N"+NOR+YEL+"�������£��տڲ������һ��"+HIC+"�������"+NOR+YEL+"�����š�\n"NOR;
	else if(level<=300) return WHT"$N"+NOR+WHT+"�տڲ�����ޱ��飬����һ��ʯ��һ�㡣\n"NOR;
	else if(level<=350) return HIW"$N"+NOR+HIW+"�������ӣ�����͸��һ��ׯ�ϵ���Ϣ��\n"NOR;
	else if(level<=400) return HIG"$N"+NOR+HIG+"������ʹ��Ϣ������֫��Ѩ��ֻ���������ָ�����һ�㡣\n"NOR;
	else return HIY"$N"+NOR+HIY+"��ɫ���飬�������������ƺ���Χ��һ���ɫ�Ĺ�â��\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("wuxiang-shengong",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"�������������񹦣��������ڵ����������������\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"������Ϣ��ֻ�����������������˵�����������\n"NOR;
	else if(level<=200) return MAG"$N"+NOR+MAG+"����������ϥ����������������"+HIB+"�������Ҿ��磬"+NOR+MAG+"һ�����ȵ���Ϣ���ζ�����֮�����ߡ�\n"NOR;
	else if(level<=250) return YEL"$N"+NOR+YEL+"�������£��տڲ������һ��"+HIC+"�������"+NOR+YEL+"�����š�\n"NOR;
	else if(level<=300) return WHT"$N"+NOR+WHT+"�տڲ�����ޱ��飬����һ��ʯ��һ�㡣\n"NOR;
	else if(level<=350) return HIW"$N"+NOR+HIW+"�������ӣ�����͸��һ��ׯ�ϵ���Ϣ��\n"NOR;
	else if(level<=400) return HIG"$N"+NOR+HIG+"������ʹ��Ϣ������֫��Ѩ��ֻ���������ָ�����һ�㡣\n"NOR;
	else return HIY"$N"+NOR+HIY+"��ɫ���飬�������������ƺ���Χ��һ���ɫ�Ĺ�â��\n"NOR;
}

string *query_exert() 
{
	return ({"roar","jinzhong"});
}


