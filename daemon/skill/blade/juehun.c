//��Ե���
//����ն
//by rzy 02.09.24

#include <ansi.h>
inherit SSERVER;

#define REDUCE_DEX -100

int perform(object me,object target) {
	object weapon;
	int damage=50+me->query("apply_points")*3/2;
	string msg;

	weapon=me->query_temp("weapon");

	if(!target)
          if(!objectp(target=offensive_target(me)))
		return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
	if(!me->is_fighting())
		return notify_fail("������ն��Ҫ��ս����ʹ�ã�\n");
	if(!weapon)
		return notify_fail("�����޷�ʹ�á�����ն����\n");
	if(weapon->query("skill_type")!="blade")
		return notify_fail("��ʹ�õ��������ԣ�\n");
	if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");
	if(!me->query_skill("wuba-daofa",1))
		return notify_fail("�㲻�ᡸ��Ե�������\n");
	if(me->query("apply_points")<=0)
		return notify_fail("������Ʋ��㣬�޷�ʹ�á�����ն����\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("�����������Ϊ��ʹ����������ն�����־�����\n");
	if((int)me->query("force")<500)
		return notify_fail("�������������\n");
	if((int)me->query_skill("blade",1)<110)
		return notify_fail("��Ļ�������̫���ˣ�\n");
	if((int)me->query_skill("wuba-daofa",1)<110)
		return notify_fail("��ġ���Ե������������ң�\n");
	if((int)me->query_skill("jiuxuan-dafa",1)<110)
		return notify_fail("��ġ������󷨡��������ң�\n");
	if(time()-me->query_temp("perform_busy")<10)
		return notify_fail("����ʩչ������ն����Ҫ������������֧�֣�����Ϊ������������У�\n");
	if(me->query_skill("yijian-shu",1)<100)
		return notify_fail("����Ľ�����Ϊ̫���ˣ�\n");

	msg=HIR"$N"+HIR+"�����Ŀ��$w"+HIR+"�Ա���ͷ������һ�����������ߣ�$w"+HIR+"����ͷ����Ȼһ�٣�˲�����ƴﵽ���壬\n"
		"˫Ŀ�������ţ������пյ�һ���������£� \n"NOR;   
	
	COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
	
	me->set("apply_points",0);
		
	me->set_temp("perform_busy",time());
	return 1;

}