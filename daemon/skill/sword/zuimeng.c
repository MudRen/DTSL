//Ʈ�ν���
//����
//by rzy 20.09.24

#include <ansi.h>
inherit SSERVER;

int perform(object me,object target) {
        
        int damage=me->query("apply_points")*2;
        object weapon;
        int ap,vp;
        
        weapon=me->query_temp("weapon");
        
        if(!target)
          if(!objectp(target=offensive_target(me)))
        	return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
        if(!me->is_fighting())
                return notify_fail("ֻ����ս��ʱ�ſ���ʹ�á����Ρ���\n");
        if(!weapon)
        	return notify_fail("�����޷�ʹ�á����Ρ���\n");
        if(weapon->query("skill_type")!="sword")
                return notify_fail("��ʹ�õ��������ԣ�\n");
        if(weapon->query("flag")==1)
        	return notify_fail("�ϵ��ı���������ʹ���ˣ�\n");
        if((int)me->query_skill("bihai-force",1)<110)
        	return notify_fail("��ġ��̺��񹦡���Ϊ̫�ͣ�\n");
        if(!me->query_skill("piaomeng-jianfa",1))
                return notify_fail("�㻹û��ѧ�ᡸƮ�ν�������\n");
        if((int)me->query("max_force")<1500)
                return notify_fail("�����������Ϊ�޷�ʹ�������Ρ�������������\n");
        if((int)me->query_skill("piaomeng-jianfa",1)<110)
                return notify_fail("��ġ�Ʈ�ν�������������죡\n");
        if((int)me->query_skill("sword",1)<110)
                return notify_fail("��Ļ��������������ң�\n");
	if(me->query("apply_points")<=0)
		return notify_fail("������Ʋ��㣬�޷�ʹ�á����Ρ���\n");
        if(time()-me->query_temp("perform_busy")<10)
                return notify_fail("����ʩչ�����Ρ���Ҫ������������֧�֣�����Ϊ������������У�\n");
        if(me->query_skill("dongming-xinfa",1)<100)
		return notify_fail("��Ķ����ķ���Ϊ̫���ˣ�\n");
        
	message_vision(HIY"\n$N"+HIY+"�������ģ�����"+weapon->name()+HIY+"���õ�����бб��ȴͻȻ�����벻���ĽǶȴ̳���һ˲�䷢�������Ĵ��ƿ���֮ \n"+
			"����������������������Ѩ����������˵ò���С���� \n"NOR,me,target);
	
	ap=me->query_dex()+me->query_int()+me->query("combat_exp")/50000;
        vp=target->query_int()+target->query_dex()+target->query("combat_exp")/50000;
   	
        if(random(ap+vp)>vp) {
        	
		if(random(ap+vp)>vp) {
			message_vision(HIR"\n"+target->name()+HIR+"û��������է���º������۵��������᲻�����±��������У���������Ϣ��$N"+HIR+"�������ص� \n"+
					"���ֱ仯������ȻϮ�塣\n"NOR,me);
                	
                	me->add_temp("apply/damage",damage);
			COMBAT_D->do_attack(me,target,weapon,0,2);
			COMBAT_D->do_attack(me,target,weapon,0,2);
			me->add_temp("apply/damage",-damage);
        	}
        	else {
        		message_vision(HIG"\n"+target->name()+HIG+"�������в���С�����������Ӳ�����˼���Ľ�����ȴû�ϵ�$N"+HIG+"���к���������仯��\n"+
        				"����������������ӭ��Ϯ����\n"NOR,me);
			me->add_temp("apply/damage",damage/2);
			COMBAT_D->do_attack(me,target,weapon,0,2);
			COMBAT_D->do_attack(me,target,weapon,0,2);
			me->add_temp("apply/damage",-damage/2);
		}

	}
	me->set_temp("perform_busy",time());
	return 1;
}

