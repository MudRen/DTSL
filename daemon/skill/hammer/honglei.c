//��������

//�������

//by rzy 02.09.24



#include <ansi.h>

inherit SSERVER;



#define REDUCE_DEX 50



int perform(object me,object target) {

	object weapon;

	int damage=me->query("apply_points")*5/2;

	int damage1=random(me->query("apply_points"));

	int ap,vp;

	string msg;



	weapon=me->query_temp("weapon");



	if(!target)

          if(!objectp(target=offensive_target(me)))

		return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");

	if(!me->is_fighting())

		return notify_fail("��������ס�Ҫ��ս����ʹ�ã�\n");

	if(!weapon)

		return notify_fail("�����޷�ʹ�á�������ס���\n");

	if(weapon->query("flag")==1)

        	return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");

	if(weapon->query("skill_type")!="hammer")

		return notify_fail("��ʹ�õ��������ԣ�\n");

	if(!me->query_skill("leiting-chuifa",1))

		return notify_fail("�㻹û��ѧ�ᡸ������������\n");

	if(me->query("apply_points")<=0)

		return notify_fail("������Ʋ��㣬�޷�ʹ�á�������ס���\n");

	if((int)me->query("max_force")<1500)

		return notify_fail("�����������Ϊ��ʹ������������ס����־�����\n");

	if((int)me->query_skill("hammer",1)<110)

		return notify_fail("��Ļ�������̫���ˣ�\n");

	if((int)me->query_skill("leiting-chuifa",1)<110)

		return notify_fail("��ġ������������������ң�\n");

	if((int)me->query_skill("bihai-force",1)<110)

		return notify_fail("��ġ��̺��񹦡��������ң�\n");

	if(time()-me->query_temp("perform_busy")<5)

		return notify_fail("����ʩչ��������ס���Ҫ������������֧�֣�����Ϊ������������У�\n");

	if(me->query_skill("dongming-xinfa",1)<100)

		return notify_fail("��Ķ����ķ���Ϊ̫���ˣ�\n");



        ap=me->query_str()+me->query_dex()+me->query("combat_exp")/50000;

        vp=target->query_str()+target->query_dex()+target->query("combat_exp")/50000;

        

          msg=HIG"\n$N"+HIG+"��Ȼ���һ�󲽣����Ϻ�����֣�����"+me->query_temp("weapon")->name()+HIG+"����һ�����磬����������������һ�����ߣ���ӯ������ʹ\n"+
			"��Χ����ѹ����Ȼ����"+me->query_temp("weapon")->name()+HIG+"��δ���壬������ѹ���˴�����������\n"NOR;

		message_vision(msg,me,target);



	if(random(ap+vp)>vp) {

		msg = HIR"$n"+HIR+"ֻ�е���������Ȼ��ɣ����޿ɱܣ�ɲʱ����һ���亹�����У��������ӣ�\n"NOR;

		

		COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);

		

	}

	else {

		msg = HIM"$n"+HIM+"ֻ�е���������Ȼ��ɣ����Զ�ܸ��޷�Ӳ�ӣ����¹˲�����ݣ����ر�����ӿ��˱�һ���ұ� \n"+

			"�����ˣ�ȴ�Ա���������һ�£�\n"NOR;                                                  

		COMBAT_D->do_perform_attack(damage1,REDUCE_DEX,msg,me,target,weapon,0,2);

		me->start_busy(random(1));

		target->start_busy(random(3));

		

	}





	me->set_temp("perform_busy",time());

	return 1;



}



