//����ָ
//��Ϭ��ָ
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
		return notify_fail("����Ϭ��ָ��ֻ����ս����ʹ��!\n");
   if(weapon)
    return notify_fail("�������������ʹ�á���Ϭ��ָ����\n");
    if(!me->query_skill("xiuluo-zhi",1))
    return notify_fail("��ѧ������ָ�����ʹ�á���Ϭ��ָ����\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("finger",1)<110)
    return notify_fail("��Ļ���ָ��̫���ˣ�\n");
    if((int)me->query_skill("xiuluo-zhi",1)<110)
    return notify_fail("��ġ�����ָ���������ң�\n");
    if((int)me->query_skill("qingxin-force",1)<100)
    return notify_fail("��ġ��������ƾ����������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ����Ϭ��ָ����\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ����Ϭ��ָ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points")/2;
    
    msg=WHT"$N"+WHT+"��̧���֣��Ƶ�һ��������˲ʱ����ָ�ݷ�������ˣ�ˮ��к�ص���$n"+WHT+"ͻȥ��\n"+
        "һ��������������ֱ�ߡ����ߡ������ǣ����߾��˵�ɱ������$n"+WHT+"��ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����Ϭ��ָ��ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"ָ����â��ָ�����ס�ָ����硢ָ������$N"+HIY+"��ָ���ݷ��������ڣ��ݺݴ��$n"+HIY+"��\n"+
        "�ӡ������š�ζ�����������ʱ$n"+HIY+"���ش���Ӱ�죬�ۿ���Ҫ����ָ�£�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����Ϭ��ָ��ֻ����ս����ʹ��!\n");
    
    msg=HIG"$N"+HIG+"����ָ��ɴ���������������û��ʱ������ƣ��ƹ�ȥ�����������ڶ�������δ��\n"+
        "��ȥ��û�пռ�����⣬˳�ֶ��ӡ����ֶ�ɨ�����ֶ��̣�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
