//����ӡ
#include <ansi.h>

inherit SSERVER;

mapping actionp1=([
		"action":RED"$N"+RED+"��������ӡ�������ĺ�����֣��͵�һ�����˳�$n"+RED+"��ȥ!"NOR,
		"damage":230,
		"parry":100,
		"dodge":40,
		"damage_type":"����",
		"skill_name":"jiuzi-zhenyan",
	]);
mapping actionp2=([
		"action":HIR"$N"+HIR+"����ӡ���ϴ߶���˫������ӿ�ֲ��ϣ�$n"+HIR+"��Щվ�������ˣ�"NOR,
		"damage":250,
		"parry":100,
		"dodge":50,
		"damage_type":"����",
		"skill_name":"jiuzi-zhenyan",
	]);
mapping actionp3=([
		"action":MAG"$N"+MAG+"����ӡ����֮�£����ܿ����д����������ˣ���$n"+MAG+"��ȥ��"NOR,
		"damage":300,
		"parry":100,
		"dodge":55,
		"damage_type":"����",
		"skill_name":"jiuzi-zhenyan",
	]);

int perform(object me,object target)
{ 
     int lev;
     object weapon;
     weapon=me->query_temp("weapon");	
     if(weapon)
    return notify_fail("�������������ʹ��[����ӡ]��\n");
    if(!me->is_fighting())
    return notify_fail("ֻ����ս��ʱ�ſ���ʹ������ӡ��\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("��ѧ[��������]���ʹ��[����ӡ]��\n");
    if((int)me->query("max_force")<5000)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query("force")<300)
    return notify_fail("�����������ʹ�ô�����!\n");
    if((int)me->query_skill("jiuzi-zhenyan",1)<100)
    return notify_fail("��ľ�������̫���ˣ�\n");
    if((int)me->query_skill("strike",1)<130)
    return notify_fail("���[�����Ʒ�]�������ң�\n");
    lev=me->query_skill("jiuzi-zhenyan",1);
    me->set("actionp",actionp1);
    COMBAT_D->do_attack(me,target,0,0,1);
    me->add("force",-100);
    me->delete("actionp");
    
    if(lev<200)
    return 1;
    if(!me->is_fighting())
    return notify_fail("ֻ����ս��ʱ�ſ���ʹ������ӡ��\n");
    if((int)me->query("force")<100)
    return notify_fail("�����������ʹ�ô�����!\n");
    me->set("actionp",actionp2);
    COMBAT_D->do_attack(me,target,0,0,1);
    me->add("force",-100);
    me->delete("actionp");
    
    if(lev<300)
    return 1;
    if(!me->is_fighting())
    return notify_fail("ֻ����ս��ʱ�ſ���ʹ������ӡ��\n");
    if((int)me->query("force")<100)
    return notify_fail("�����������ʹ�ô�����!\n");
    me->set("actionp",actionp3);
    COMBAT_D->do_attack(me,target,0,0,1);
    me->add("force",-100);
    me->delete("actionp");
    me->set_temp("perform_busy",time()+5);
    return 1;   
  
}  
