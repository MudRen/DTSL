//���ȭ
//������
//by rzy 02.9.17

#include <ansi.h>
inherit SSERVER;

int perform(object me,object target) {
	int i;
	object weapon;
	weapon=me->query_temp("weapon");  

	if(!target)
          if(!objectp(target=offensive_target(me)))
		return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
	if(!me->is_fighting())
		return notify_fail("ֻ����ս��ʱ�ſ���ʹ�á������꡹��\n");
	if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
	if(weapon)
		return notify_fail("���������޷�ʹ�á������꡹��\n");
	if(me->query_temp("perform_zhenhun"))
		return notify_fail("������ʹ�á������꡹��\n");
	if(!me->query_skill("tiangang-quan",1))
		return notify_fail("�㻹û��ѧ�ᡸ���ȭ����\n");
	if((int)me->query("max_force")<1000)
		return notify_fail("�����������Ϊ�޷�ʹ���������꡹������������\n");
	if((int)me->query_skill("wuxiang-shengong",1)<110)
		return notify_fail("��ġ������񹦡��������ң�\n");
	if((int)me->query_skill("tiangang-quan",1)<110)
		return notify_fail("��ġ����ȭ����������죡\n");
	if((int)me->query_skill("cuff",1)<110)
		return notify_fail("��Ļ���ȭ���������ң�\n");
	if(me->query_skill("bikouchan",1)<100)
		return notify_fail("��ıտ�����Ϊ̫���ˣ�\n");
	if(time()-me->query_temp("perform_busy")<5)
		return notify_fail("��ո�ʹ�ù��������꡹����Ϣ��δƽ����\n");
	if(me->query("force")<500)
	 return notify_fail("�������������\n");
		
	message_vision(HIR"$N"+HIR+"���д���һ�����������ת˲���������ס�ֻ��$N"+HIR+"�����������ͣ�������ӯȫ������ׯ�ϣ�\n"+
			"�����޺��콵һ�㣬���ǡ������������\n"NOR,me,target);
		i=me->query_skill("tiangang-quan",1)*2/3+me->query("apply_points");
		me->add_temp("apply/damage",i);
		me->set_temp("perform_zhenhun",1);
		me->add("force",-500);
    
		call_out("rid_damag",me->query_skill("tiangang-quan",1)/5,me,i);
		return 1;   
}

void rid_damag(object me,int i) {
	if(!me)
		return;
	message_vision(HIR"\n$N"+HIR+"������һ����ţ������ջ�������\n"NOR,me);
	me->add_temp("apply/damage",-i);
	me->delete_temp("perform_zhenhun");
	me->set_temp("perform_busy",time());
	return;
}
