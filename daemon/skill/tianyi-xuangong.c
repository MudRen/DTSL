//��һ�������������书��

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
     return 1;
}


int practice_skill(object me)
{
          return notify_fail("��һ����ֻ��ͨ��ѧ�����!\n");
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
	level=(int)me->query_skill("tianyi-xuangong",1);
	if(me->query_skill("busi-yin",1)) level2=me->query_skill("busi-yin",1);
    if(level&&level2){
		if((level/2+level2)<50) return 15;
        if((level/2+level2)<120) return 20;
		return 35;}
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
	level=(int)me->query_skill("tianyi-xuangong",1);
	level2=me->query_skill("busi-yin",1);
	if(level&&level2){
		if((level/2+level2)<50) return 20;
        if((level/2+level2)<120) return 25;
		return 35;}
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
	level=(int)me->query_skill("tianyi-xuangong",1);
	if(level<=50) return HIG"$N"+HIG+"��ϥ�������������������ϳ��ֳ�һƬ��͵�����.\n"NOR;
	else if(level<=120) return CYN"$N"+NOR+CYN+"��Ϣ��Ȼ��"+HIW+"����ȫ��"+NOR+CYN+"���ѳ�Ȼ����.\n"NOR;
	else return HIY"$N"+HIY+"��ϥ����������"+HIR+"���"+HIY+"������Χ��������һ��.\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("tianyi-xuangong",1);
	if(level<=50) return HIG"$N"+HIG+"��ϥ�������������������ϳ��ֳ�һƬ��͵�����.\n"NOR;
	else if(level<=120) return CYN"$N"+NOR+CYN+"��Ϣ��Ȼ��"+HIW+"����ȫ��"+NOR+CYN+"���ѳ�Ȼ����.\n"NOR;
	else return HIY"$N"+HIY+"��ϥ����������"+HIR+"���"+HIY+"������Χ��������һ��.\n"NOR;
}
string *query_exert() 
{
	return ({"yin"});
}


