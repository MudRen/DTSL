//�ɽ�ָ
//һָ��
//by rzy 02.9.18

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
                return notify_fail("ֻ����ս��ʱ�ſ���ʹ�á�һָ������\n");
        if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
        if(weapon)
                return notify_fail("���������޷�ʹ�á�һָ������\n");
        if((int)me->query_skill("wuxiang-shengong",1)<110)
        	return notify_fail("��ġ������񹦡���Ϊ̫�ͣ�\n");
        if(!me->query_skill("dujie-zhi",1))
                return notify_fail("�㻹û��ѧ�ᡸ�ɽ�ָ����\n");
        if((int)me->query("max_force")<1000)
                return notify_fail("�����������Ϊ�޷�ʹ����һָ����������������\n");
        if((int)me->query_skill("dujie-zhi",1)<110)
                return notify_fail("��ġ��ɽ�ָ����������죡\n");
        if((int)me->query_skill("finger",1)<110)
                return notify_fail("��Ļ���ָ���������ң�\n");
	if(me->query("apply_points")<=0)
		return notify_fail("������Ʋ��㣬�޷�ʹ�á�һָ������\n");
        if(time()-me->query_temp("perform_busy")<6)
                return notify_fail("����ʩչ��һָ������Ҫ������������֧�֣�����Ϊ������������У�\n");
        if(me->query_skill("bikouchan",1)<100)
		return notify_fail("��ıտ�����Ϊ̫���ˣ�\n");
        
        ap=me->query_int()+me->query_dex()+me->query("combat_exp")/50000;
        vp=target->query_int()+target->query_dex()+target->query("combat_exp")/50000;
        
	message_vision(MAG"$N"+MAG+"���ο���ת�������и�����ţ������ŷ�����ָ������˲�䷢������ָ����ֱϮ����$n"+MAG+"�� \n"NOR,me,target);
		
        if(!target->query_temp("weapon")) {
        	
        	if(random(ap+vp)>vp) {
                	message_vision(HIR"\n$N"+HIR+"��$n"+HIR+"��ָ�����У������޷����ۣ���ʱ����һ�飡\n"NOR,target,me);
                	target->start_busy(3);         
        	}
        	else {
			message_vision(HIY"\n$N"+HIY+"����Ծ�𣬰������������ת����$n"+HIY+"��ָ����Ȼȫ����գ�\n"NOR,target,me);
			me->start_busy(random(2)); 
		}
	}
        if(target->query_temp("weapon")) {
        	
        	if( random(ap+vp)>vp) {
        		message_vision(HIR"\n$N"+HIR+"��$n"+HIR+"��ָ�����У�������ɢ��ֻ������"+target->query_temp("weapon")->name()+HIR+"����ǧ��֮�أ�һ���ѳֲ�ס�������ַɳ���\n"NOR,target,me);	
			target->query_temp("weapon")->move(environment(target));
		}
		else {
			message_vision(HIY"\n$N"+HIY+"��$n"+HIY+"��ָ�����У�����һ����ֻ������"+target->query_temp("weapon")->name()+HIY+"���ϼ��أ���æ�������գ�\n"NOR,target,me);
			target->start_busy(1);
			me->start_busy(2);
		}
	}
	me->set_temp("perform_busy",time());
	return 1;
}