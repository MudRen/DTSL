//��ħ��.�������书.

inherit FORCE;
#include <ansi.h>


int valid_learn(object me)
{       
    
	if(me->query_skill("force",1)<10)
		return notify_fail("��Ļ����ڹ���Ϊ�������޷�������ħ�󷨡�\n");
    if(me->query_skill("tianmo-dafa",1)>=100&&
		me->query("bellicosity")<100)
		return notify_fail("���ɱ��̫���ˣ��޷�������ħ�󷨡�\n");
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("����ħ�󷨡�ֻ��ͨ��ѧ�����!\n");
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
	int lev;
	lev=me->query_skill("tianmo-dafa",1);
	
	if(lev<=50) return 15;
	else if(lev<=100) return 25;
	else if(lev<=150) return 30;
	else return 40;
}

int query_respirate(object me) //����ʱ����.
{
	int lev;
	lev=(int)me->query_skill("tianmo-dafa",1);
	
	if(lev<=50) return -10;
	else if(lev<=100) return -15;
	else if(lev<=150) return -20;
	else return -50;

}

string sub_exercise(object me)
{
  int lev;
  lev=(int)me->query_skill("tianmo-dafa",1);
  if(lev<=100) return BLU"$N"+NOR+BLU+"����������ħ����ʹ��Χ�����������С�\n"NOR;
  else if(lev<=150) return HIM"$N"+NOR+HIM+"��Ϊ������������ħ������ʱ�淺��⡣\n"NOR;
  else if(lev<=200) return MAG"$N"+NOR+MAG+"������������ɫ���������⣬��ħ���������������ˡ�\n"NOR;
  else if(lev<=250) return WHT"$N"+NOR+WHT+"���Ц�ݵ����������������һ�㡣\n"NOR;
  else if(lev<=300) return HIW"$N"+NOR+HIW+"˫������ط���˫ϥ֮�ϣ���̬���ţ����˶�����֮�ġ�\n"NOR;
  else if(lev<=350) return HIG"$N"+NOR+HIG+"����֮������ħ��һ�㣬��������������ʧȥ����֮����\n"NOR;
  else if(lev<=400) return RED"$N"+RED+"��ɫ���ģ��쳣��������֮ɫ�������˶�ʧ���ǡ�\n"NOR;
  else return HIR"$N"+NOR+HIR+"�������ɰ��������һ��ħ���������κ��˷���\n"NOR;
}

string sub_respirate(object me)
{
  int lev;
  lev=(int)me->query_skill("tianmo-dafa",1);
  if(lev<=100) return BLU"$N"+NOR+BLU+"����������ħ����ʹ��Χ�����������С�\n"NOR;
  else if(lev<=150) return HIM"$N"+NOR+HIM+"��Ϊ������������ħ������ʱ�淺��⡣\n"NOR;
  else if(lev<=200) return MAG"$N"+NOR+MAG+"������������ɫ���������⣬��ħ���������������ˡ�\n"NOR;
  else if(lev<=250) return WHT"$N"+NOR+WHT+"���Ц�ݵ����������������һ�㡣\n"NOR;
  else if(lev<=300) return HIW"$N"+NOR+HIW+"˫������ط���˫ϥ֮�ϣ���̬���ţ����˶�����֮�ġ�\n"NOR;
  else if(lev<=350) return HIG"$N"+NOR+HIG+"����֮������ħ��һ�㣬��������������ʧȥ����֮����\n"NOR;
  else if(lev<=400) return RED"$N"+RED+"��ɫ���ģ��쳣��������֮ɫ�������˶�ʧ���ǡ�\n"NOR;
  else return HIR"$N"+NOR+HIR+"�������ɰ��������һ��ħ���������κ��˷���\n"NOR;
}

string *query_exert() //exert ����.
{
	return ({"tianmo","huihun","jufen","moxin"});
}

void skill_improved(object me)
{
	int lv = (int)me->query_skill("tianmo-dafa", 1);   

	if (lv == 40)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�һ���ˡ�\n"NOR);
	if (lv == 80)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵ڶ����ˡ�\n"NOR);
	if (lv == 120) 
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵������ˡ�\n"NOR);
	if (lv == 140)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵��Ĳ��ˡ�\n"NOR);
	if (lv == 160)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�����ˣ�������书������ǿ�ˡ�\n"NOR);
	if (lv == 180)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵������ˡ�\n"NOR);
	if (lv == 200)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵��߲��ˡ�\n"NOR);
	if (lv == 220)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵ڰ˲��ˡ�\n"NOR);
	if (lv == 240)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵ھŲ��ˡ�\n"NOR);
	if (lv == 260)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�ʮ���ˣ�������书�в�С��ǿ��\n"NOR);
	if (lv == 280)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�ʮһ���ˡ�\n"NOR);
	if (lv == 300)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�ʮ�����ˡ�\n"NOR);
	if (lv == 320)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�ʮ�����ˡ�\n"NOR);
	if (lv == 340)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�ʮ�Ĳ��ˣ�������书�кܴ����ǿ��\n"NOR);
	if (lv == 360)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�ʮ����ˡ�\n"NOR);
	if (lv == 380)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�ʮ�����ˡ�\n"NOR);
	if (lv == 400)
		tell_object(me,HIW"��ħ��ʮ�˲������Ѿ��������˵�ʮ�߲��ˣ��ڻ�������书�Ѿ����˺ܴ��ͻ�ơ�\n"NOR);
	if (lv == 450
	    &&!me->query("tianmodafa_quest_allok")
	    &&!me->query("tianmodafa_quest_ok"))
		tell_object(me,HIR"���Ѿ��ӽ���ħ�󷨵�ʮ�˲㾳���ˣ�ֻ��һ��ͻ�ơ�\n"NOR);
	if (me->query("tianmodafa_quest_allok")||me->query("tianmodafa_quest_ok"))
		tell_object(me,RED"�����ħ���Ѿ���ͨ��ʮ�˲㾳�磡��������ˣ�\n"NOR);
		
}

string query_level_msg(object me,int lv)
{
	
	if (lv <= 40)
		return BLU"�� һ ��"NOR;
	if (lv <= 80)
		return BLU"�� �� ��"NOR;
	if (lv <= 120) 
		return HIB"�� �� ��"NOR;
	if (lv <= 140)
		return HIB"�� �� ��"NOR;
	if (lv <= 160)
		return HIB"�� �� ��"NOR;
	if (lv <= 180)
		return CYN"�� �� ��"NOR;
	if (lv <= 200)
		return CYN"�� �� ��"NOR;
	if (lv <= 220)
		return CYN"�� �� ��"NOR;
	if (lv <= 240)
		return CYN"�� �� ��"NOR;
	if (lv <= 260)
		return CYN"�� ʮ ��"NOR;
	if (lv <= 280)
		return HIC"��ʮһ��"NOR;
	if (lv <= 300)
		return HIC"��ʮ����"NOR;
	if (lv <= 320)
		return HIC"��ʮ����"NOR;
	if (lv <= 340)
		return HIW"��ʮ�Ĳ�"NOR;
	if (lv <= 360)
		return HIG"��ʮ���"NOR;
	if (lv <= 380)
		return HIG"��ʮ����"NOR;
	if (lv <= 400)
		return HIR"��ʮ�߲�"NOR;
	if(!me->query("tianmodafa_quest_allok")&&
	   !me->query("tianmodafa_quest_ok"))
	   return HIR"��ʮ�߲�"NOR;
	return RED"��ʮ�˲�"NOR;
		
}