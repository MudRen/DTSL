//ˮ���䷨

//�����޾�

//by rzy 02.09.24



#include <ansi.h>

inherit SSERVER;



int perform(object me,object target) {

        object weapon;

        int ap,vp;

   

        weapon=me->query_temp("weapon");

        

        if(!target)

          if(!objectp(target=offensive_target(me)))

        	return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");

        if(!me->is_fighting())

                return notify_fail("ֻ����ս��ʱ�ſ���ʹ�á������޾�����\n");

        if(!weapon)

                return notify_fail("�����޷�ʹ�á������޾�����\n");

        if(weapon->query("skill_type")!="whip")

		return notify_fail("��ʹ�õ��������ԣ�\n");

	if(weapon->query("flag")==1)

		return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");

        if((int)me->query_skill("bihai-force",1)<110)

        	return notify_fail("��ġ��̺��񹦡���Ϊ̫�ͣ�\n");

        if(!me->query_skill("shuiyun-xiufa",1))

                return notify_fail("�㻹û��ѧ�ᡸˮ���䷨����\n");

        if((int)me->query("max_force")<1000)

                return notify_fail("�����������Ϊ�޷�ʹ���������޾���������������\n");

        if((int)me->query_skill("shuiyun-xiufa",1)<110)

                return notify_fail("��ġ�ˮ���䷨����������죡\n");

        if((int)me->query_skill("whip",1)<110)

                return notify_fail("��Ļ����޷��������ң�\n");

	if(me->query("apply_points")<=0)

		return notify_fail("������Ʋ��㣬�޷�ʹ�á������޾�����\n");

        if(time()-me->query_temp("perform_busy")<4)

                return notify_fail("����ʩչ�������޾�����Ҫ������������֧�֣�����Ϊ������������У�\n");

        if(me->query_skill("dongming-xinfa",1)<100)

		return notify_fail("��Ķ����ķ���Ϊ̫���ˣ�\n");

	

	ap=me->query_str()+me->query_dex()+me->query("combat_exp")/50000;

        vp=target->query_str()+target->query_dex()+target->query("combat_exp")/50000;

        

	message_vision(MAG"����$N"+MAG+"��ʲô����������"+weapon->name(me)+MAG+"ȴ��Ȼ��ǰһȦȦ�ľ��˹������ھ����᲻�ϣ��·�������಻����\nû�����˵�ʱ�� \n"NOR,me,target);

		

		

        if(!target->query_temp("weapon")) {

        	

        	if(random(ap+vp)>vp) {

                	message_vision(HIB"\n"+target->name()+HIB+"��$N"+HIB+"���ھ����˽�ȥ�����������ĸ���ת�˼���Ȧ��\n"NOR,me,target);

                	target->start_busy(4);         

        	}

        	else {

			message_vision(HIG"\n"+target->name()+HIG+"�������鲻�����ˣ�$N"+HIG+"�ľ���ȫ������ˣ�\n"NOR,me,target);

			me->start_busy(random(2)); 

		}

	}

        if(target->query_temp("weapon")) {

        	

        	if(random(ap+vp)>vp) {

        		message_vision(HIR"\n"+target->name()+HIR+"�����ھ��������ᣬȴ����񣬵��¹�������������ɢ��\nȴһû�������е�"+target->query_temp("weapon")->name()+HIR+"��"+weapon->name(me)+HIR+"���˹������˸���ʵ��\n"NOR,me,target);	

			target->start_busy(random(3));

		}

		else {

			message_vision(HIW"\n"+target->name()+HIW+"���ô��в��ƿ���ȥһ��򵥣���������"+target->query_temp("weapon")->name()+HIW+"Ծ�˿�ȥ��\n"NOR,me,target);

			me->start_busy(random(2)); 

		}

	}

	me->set_temp("perform_busy",time());

	return 1;

}