//��ħ�ȷ���
//��շ�ħ��

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -100

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage;
    
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
    
   if(!me->is_fighting())
	   return notify_fail("����շ�ħ��ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="staff")
    return notify_fail("�������ȣ����ʹ�á���շ�ħ����\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
    if(!me->query_skill("fumo-zhangfa"))
    return notify_fail("��ѧ��ħ�ȷ����ʹ�á���շ�ħ����\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("���������Ϊ̫���ˣ�\n");
    if((int)me->query_skill("staff",1)<110)
    return notify_fail("��Ļ����ȷ�̫���ˣ�\n");
    if((int)me->query_skill("fumo-zhangfa",1)<110)
    return notify_fail("��ķ�ħ�ȷ��������ң�\n");
    if((int)me->query_skill("wuxiang-shengong",1)<100)
    return notify_fail("��ġ������񹦡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ������շ�ħ����\n");
    if(me->query("perform_quest/fumo")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ����շ�ħ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/fumo")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ����շ�ħ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/fumo"))
    damage=damage/2;
	
    msg=HIG"$N"+HIG+"���е�$w"+HIG+"��򵥵���һ�º�ɨ������ʵ�������仯���ţ�������������Ĳ�����\n"+
        "ʵ�ǲ����мܡ���������$w"+HIG+"�ɻ����죬�����������$n"+HIG+"��ȫ�������ڣ���Ҫ��$n"+HIG+"����\n"+
        "����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����շ�ħ��ֻ����ս����ʹ�ã�\n");
    
    msg=YEL"$N"+YEL+"��ɫ���ȣ�����$w"+YEL+"��ʽ��������ȴ�ƺ��Ǻ���ǧ��֮����$n"+YEL+"ȫ��$N"+YEL+"���ص��������֣�\n"+
        "������������$w"+YEL+"���Լ���$l�ҹ�����ƫ���޷���ܣ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����շ�ħ��ֻ����ս����ʹ�ã�\n");
    
    msg=HIC"$N"+HIC+"�Ĺ���ͻȻ���������������ֻ��$w"+HIC+"��ȡ��һ�㣬��ȴ��$n"+HIC+"��ȫ���֣�ʹ��������\n"+
        "�������ĸо���������ǣ���£�$n"+HIC+"����һ�����־��ܵļ���\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����շ�ħ��ֻ����ս����ʹ�ã�\n");
    
    if(!me->query("perform_quest/fumo")){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    msg=HIY"$N"+HIY+"˫Ŀ΢�������о�â˸������������������ĺ����������$w"+HIY+"��ֱ��ͷ����һ����\n"+
        "����������Ϊ���ľ��𣬵��ϵĲ�Ҷ���������������裬�ͺ�һ���������ӷ𡱣�\n"+
        "ֻ��$w"+HIY+"��$N"+HIY+"���зɳ�ֱ��$n"+HIY+"��$l����ȥ��\n"NOR;
    
    damage += damage/3;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    msg="\n$Nһ̽�֣���ס��"+weapon->name()+"��\n";
    message_vision(msg,me);
   
    me->set_temp("perform_busy",time());
    return 1;   
  
}  

