//��ħ�ȷ�
//��ս���
//by rzy 02.9.19

#include <ansi.h>
inherit SSERVER;

int perform(object me,object target) {
	object weapon;
	int damage=me->query("apply_points")*5/2;
	string msg;
	int ap,vp;

	weapon=me->query_temp("weapon");

	if(!target)
          if(!objectp(target=offensive_target(me)))
		return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
	if(!me->is_fighting())
		return notify_fail("����ս�����Ҫ��ս����ʹ�ã�\n");
	if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
	if(!weapon)
		return notify_fail("�����޷�ʹ�á���ս�������\n");
	if(weapon->query("skill_type")!="staff")
		return notify_fail("��ʹ�õ��������ԣ�\n");
	if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");
	if(!me->query_skill("fumo-zhangfa",1))
		return notify_fail("�㻹û��ѧ�ᡸ��ħ�ȷ�����\n");
	if(me->query("apply_points")<=0)
		return notify_fail("������Ʋ��㣬�޷�ʹ�á���ս�������\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("�����������Ϊ��ʹ��������ս��������־�����\n");
	if((int)me->query_skill("staff",1)<110)
		return notify_fail("��Ļ����ȷ�̫���ˣ�\n");
	if((int)me->query_skill("fumo-zhangfa",1)<110)
		return notify_fail("��ġ���ħ�ȷ����������ң�\n");
	if((int)me->query_skill("wuxiang-shengong",1)<110)
		return notify_fail("��ġ������񹦡��������ң�\n");
	if(time()-me->query_temp("perform_busy")<10)
		return notify_fail("����ʩչ����ս�������Ҫ������������֧�֣�����Ϊ������������У�\n");
	if(me->query_skill("bikouchan",1)<100)
		return notify_fail("��ıտ�����Ϊ̫���ˣ�\n");
	
	ap=me->query_str()+me->query_dex()+me->query("combat_exp")/50000;
        vp=target->query_str()+target->query_dex()+target->query("combat_exp")/50000;

	msg=HIR"$N"+HIR+"ͻȻ���һ����̤����ǰ����ȫ��������ע��"+me->query_temp("weapon")->name()+HIR+"�ϸ߸߾ٹ�ͷ����\n����Ϊ׾��Ӳ��$n"+HIR+"ͷ����ȥ��\n"NOR;
		message_vision(msg,me,target);

	if(random(ap+vp/3)>vp) {
		msg = HIW"$nֻ�е��������������Լ���·��ȫ���������޶��֮�����ۿ�$w����ͷ������\n"NOR;
		me->add_temp("apply/damage",damage);
		me->set_temp("action_msg",msg);
		COMBAT_D->do_attack(me,target,weapon,0,2);
		me->add_temp("apply/damage",-damage);
		me->delete_temp("action_msg");
		
	}
	else {
		msg = HIY"\n$nֻ�е��������������Լ���·��ȫ���������޶��֮��������֮�¾�����ȫ����Ӳ����$N���У�\n"NOR;          
		message_vision(msg, me, target);                                        
		me->start_busy(random(4));
		target->start_busy(random(2));                          
		
	}


	me->set_temp("perform_busy",time());
	return 1;

}
