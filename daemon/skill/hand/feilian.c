//ħ������:������
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

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
		return notify_fail("��������ֻ����ս����ʹ��!\n");
   if(weapon)
    return notify_fail("�������������ʹ�á���������\n");
    if(!me->query_skill("moxin-lianhuan"))
    return notify_fail("��ѧ��ħ�����������ʹ�á���������\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("strike",1)<110)
    return notify_fail("��Ļ����Ʒ�̫���ˣ�\n");
    if((int)me->query_skill("moxin-lianhuan",1)<110)
    return notify_fail("��ġ�ħ���������������ң�\n");
    if((int)me->query_skill("tianmo-dafa",1)<100)
    return notify_fail("��ġ���ħ�󷨡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ����������\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ����������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points")/2;
    
    msg=YEL"$N"+YEL+"�������ִ�����̽������һ��׷�����������㣬���������ӡ������ҪӲ����\n"+
    "��ʵ�õ�ȴ��ж�Ƶľ����ַ�������$n"+YEL+"������ʩ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��������ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"һ����������ʩ������̤�沽��˫�ֺ�£������ɲ�Ǽ��Ƴ�����������\n"+
    "�ֱ�Ϯ��$n"+HIY+"���Ҽ羮Ѩ�����ţ��������գ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��������ֻ����ս����ʹ��!\n");
    
    msg=HIR"$N"+HIR+"ٿ������$n"+HIR+"���洦�����ݰ���ת������£���������ƣ������������죬���˶�\n"+
        "�ģ�����ʢ����������������$n"+HIR+"ӡȥ�������������������ǣ���������㣡\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
