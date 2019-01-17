#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 30

int perform(object me, object target)
{
        object weapon;
        string str;
        int i;
        int damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("���Ķϻ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("tianmo-zhan", 1) < 160 )
                return notify_fail("�����ħն����̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("dagger", 1) < 160 )
                return notify_fail("��Ļ���ذ������̫ǳ���������ˡ�\n");
        if( (int)me->query_skill("tianmo-dafa", 1) < 160 )
                return notify_fail("�����ħ��̫ǳ���������ˡ�\n");
        if(me->query("apply_points")<=0)
                return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�����Ķϻ꡹��\n");        
        if( (int)me->query("max_force") < 1800 )
                return notify_fail("�������̫�٣��������ˡ�\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("��������������������ˡ�\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "dagger")
                return notify_fail("��ʹ������ħն����ô?\n");
        if( time()-me->query_temp("perform_busy")<4)
                return notify_fail("�������������㣬�޷��������⹥����\n");

        if( me->query_temp("yg_souxin"))
                return notify_fail("���ʹ�꡸���Ķϻ꡹��Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

        message_vision(HIR "\n$NͻȻ��Хһ��������"+weapon->name(me)+HIR+"�ڰ���л���������⣬һ������ħ������$n"+HIR+"��Ϯ��ȥ��\n" NOR,me, target);
        me->set_temp("yg_souxin", 2); 

        damage=me->query("apply_points");

        damage=damage/3;
        
        COMBAT_D->do_perform_attack(damage,REDUCE_DEX,"",me,target,weapon,0,2);

        if(me->is_fighting(target)){
        	COMBAT_D->do_perform_attack(damage,REDUCE_DEX,"",me,target,weapon,0,2);
        }
        if(me->is_fighting(target)){
	        COMBAT_D->do_perform_attack(damage,REDUCE_DEX,"",me,target,weapon,0,2);
        }
        me->set_temp("yg_souxin", 1);      
        me->set_temp("perform_busy",time());
        i = (int)me->query_skill("dagger")/25;
        if( 10 - i <= 4) i = 4;
        call_out("remove_effect", i, me);
        
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("yg_souxin");
        tell_object(me, HIR"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á����Ķϻ꡹�ˡ�\n"NOR); 
        return;
}
