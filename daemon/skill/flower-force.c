//�ɻ���ˮ��
//�������书

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
     return 1;
}


int practice_skill(object me)
{
          return notify_fail("�ɻ���ˮֻ��ͨ��ѧ�����!\n");
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
	int level,level2;
	level=0;level2=0;
	level=(int)me->query_skill("flower-force",1);
	if(me->query_skill("busi-yin",1)) level2=me->query_skill("busi-yin",1);
    if(level&&level2){
		if((level/2+level2)<50) return 15;
        if((level/2+level2)<120) return 20;
		return 35;
	}
	else{
		if(level<50) return 15;
		if(level<120) return 20;
		return 25;
	}
}

int query_respirate(object me)
{
	int level,level2;
	level=0;level2=0;
	level=(int)me->query_skill("flower-force",1);
	level2=me->query_skill("busi-yin",1);
	if(level&&level2){
		if((level/2+level2)<50) return 20;
        if((level/2+level2)<120) return 25;
		return 35;
	}
	else{
		if(level<=50)
			return 20;
		else if(level<=120) return 22;
		else return 25;
	}

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("flower-force",1);
	if(level<=100) return BLU"$N"+NOR+BLU+"��ϥ������������ɫ���粻����\n"NOR;
	else if(level<=150) return HIB"$N"+NOR+HIB+"���΢Ц��˫Ŀ΢�գ��ƺ�˿���о��������ϵ��κη��ա�\n"NOR;
	else if(level<=200) return WHT"$N"+NOR+WHT+"��ɫ��ͣ�Ц�ݸ��棬����������\n"NOR;
	else if(level<=250) return HIC"$N"+NOR+HIC+"��ָ����״����̬�����������������Ϣ����˿��������\n"NOR;
	else if(level<=300) return HIG"$N"+NOR+HIG+"��ϥ������˫��΢΢��������������������������Х֮����\n"NOR;
	else if(level<=350) return HIY"$N"+NOR+HIY+"��ָ����״����ɫ��ͣ�����һ˿���顣\n"NOR;
	else if(level<=400) return MAG"$N"+NOR+MAG+"��Ϣ��Ȼ����ɫ���糬��������֮��һ�㡣\n"NOR;
	else return HIM"$N"+NOR+HIM+"����֮�䣬"+HIG+"�����������ձ�����һ�֣�"+HIM+"�ƺ����ѳ�����������硣\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("flower-force",1);
	if(level<=100) return BLU"$N"+NOR+BLU+"��ϥ������������ɫ���粻����\n"NOR;
	else if(level<=150) return HIB"$N"+NOR+HIB+"���΢Ц��˫Ŀ΢�գ��ƺ�˿���о��������ϵ��κη��ա�\n"NOR;
	else if(level<=200) return WHT"$N"+NOR+WHT+"��ɫ��ͣ�Ц�ݸ��棬����������\n"NOR;
	else if(level<=250) return HIC"$N"+NOR+HIC+"��ָ����״����̬�����������������Ϣ����˿��������\n"NOR;
	else if(level<=300) return HIG"$N"+NOR+HIG+"��ϥ������˫��΢΢��������������������������Х֮����\n"NOR;
	else if(level<=350) return HIY"$N"+NOR+HIY+"��ָ����״����ɫ��ͣ�����һ˿���顣\n"NOR;
	else if(level<=400) return MAG"$N"+NOR+MAG+"��Ϣ��Ȼ����ɫ���糬��������֮��һ�㡣\n"NOR;
	else return HIM"$N"+NOR+HIM+"����֮�䣬"+HIG+"�����������ձ�����һ�֣�"+HIM+"�ƺ����ѳ�����������硣\n"NOR;
}
string *query_exert() 
{
	return ({"feihua","liushui"});
}
