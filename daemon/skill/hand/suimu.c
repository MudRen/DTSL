//ľ�˵� perform

#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage;
   
    weapon=me->query_temp("weapon");
    
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
    if(!me->is_fighting())
    return notify_fail("����ľ��ֻ����ս����ʹ��!\n");
   
    if(time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ����ľ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=target->query("max_pot")-60;
    
    if(target->query("combat_exp")<150000)
    damage=damage/2;
    
    msg="$N���ڻ���ͻȻ���������̹����糱ˮӿ����������ʽ���������ָ��ɵľ�ѧ��\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    if(!me) return 1;
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    if(!me->is_fighting())
    return notify_fail("����ľ��ֻ����ս����ʹ��!\n");
    
    msg="$NͻȻ������ֻ�������ֳ�������ľȭͷ���䲻����$n��ȥ��\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    if(!me) return 1;
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    if(!me->is_fighting())
    return notify_fail("����ľ��ֻ����ս����ʹ��!\n");
    
    msg="$NͻȻ�ֽ����������������һ��ԲͰ����$n��$l��ײȥ��\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    if(!me) return 1;
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
