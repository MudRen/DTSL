//�ۻ���ʽ
//�ۻ�
//by rzy 02.9.16
#include <ansi.h>
inherit SSERVER;

#define REDUCE_DEX -150

int perform(object me,object target) {
	object weapon;
	int damage=me->query("apply_points"),flag=0;
	string msg;

	weapon=me->query_temp("weapon");

	if(!target)
          if(!objectp(target=offensive_target(me)))
		return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
	if(!me->is_fighting())
		return notify_fail("���ۻ���Ҫ��ս����ʹ�ã�\n");
	if(!weapon)
		return notify_fail("�����޷�ʹ�á��ۻ�����\n");
	if(weapon->query("skill_type")!="blade")
		return notify_fail("��ʹ�õ��������ԣ�\n");
	if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");
	if(!me->query_skill("zhehua-baishi",1))
		return notify_fail("�㲻�ᡸ�ۻ���ʽ����ô��ʹ�á��ۻ�����\n");
	if(me->query("apply_points")<=0)
		return notify_fail("������Ʋ��㣬�޷�ʹ�á��ۻ�����\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("�����������Ϊ��ʹ�������ۻ������־�����\n");
	if((int)me->query_skill("blade",1)<110)
		return notify_fail("��Ļ�������̫���ˣ�\n");
	if((int)me->query_skill("zhehua-baishi",1)<110)
		return notify_fail("��ġ��ۻ���ʽ���������ң�\n");
	if((int)me->query_skill("flower-force",1)<110)
		return notify_fail("��ġ��ɻ���ˮ���������ң�\n");
	if(time()-me->query_temp("perform_busy")<10)
		return notify_fail("����ʩչ���ۻ�����Ҫ������������֧�֣�����Ϊ������������У�\n");
	if(me->query_skill("huachan",1)<100)
		return notify_fail("��Ļ�����Ϊ̫���ˣ�\n");

	msg=HIG"$N"+HIG+"˫Ŀ�������ţ�$w"+HIG+"��ǰ���̣�$w��͸��һ�����������ε��ڼ���������$n"+HIG+"�����ȥ��\n"
		"��Ȼ����������������������\n"NOR;   
		
		flag += COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
		
		
        if(!me->is_fighting())
                 return 1;
        else if(flag && random(10)>4) {
		msg=HIR"\n"+"$n"+HIR+"����Ѩ����$N�������������޷�������ж���\n"NOR;
		message_vision(msg,me,target);
		target->start_busy(random(3)); 
	}
	me->set_temp("perform_busy",time());
	return 1;

}
