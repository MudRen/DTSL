//��ѩ����
//���籩ѩ
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
		return notify_fail("�����籩ѩ��ֻ����ս����ʹ��!\n");
   if(weapon)
    return notify_fail("�������������ʹ�á����籩ѩ����\n");
    if(!me->query_skill("fengxue-leg",1))
    return notify_fail("��ѧ����ѩ���ȡ����ʹ�á����籩ѩ����\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("leg",1)<110)
    return notify_fail("��Ļ����ȷ�̫���ˣ�\n");
    if((int)me->query_skill("fengxue-leg",1)<110)
    return notify_fail("��ġ���ѩ���ȡ��������ң�\n");
    if((int)me->query_skill("jiuxuan-dafa",1)<100)
    return notify_fail("��ġ������󷨡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�����籩ѩ����\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ�����籩ѩ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points")/2;
    
    msg=HIG"$N"+HIG+"�����Եõ�һ����$n"+HIG+"������$n"+HIG+"��������ȫ��$N"+HIG+"��һ��������ȥ�����������ںδ���\n"+
        "�⿴��ƽƽ�����һ�ŷ��������ƾ����������ѩ����$n"+HIG+"�ĸй���ȫ�������У�������\n"+
        "Ҳ�类��̣�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����籩ѩ��ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"¶����ȻʧЦ����ɫ���������,׿����գ��������������Ʈ���½���ͬʱ�ż���\n"+
        "�㣬����$n"+HIY+"��$l�����$N"+HIY+"ƾ�����֮�������ݰ㼱���������������������\n"+
        "�쵽���㣡\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����籩ѩ��ֻ����ս����ʹ��!\n");
    
    msg=WHT"$N"+WHT+"����һ������Ȼ�����Ʈ�𣬶����ƻ�ʵ�죬ٿ����������$n"+WHT+"��ߣ�˫������������\n"+
        "$n"+WHT+"���ţ���������Ѹ�죬��$n"+WHT+"����ʤ����$N"+WHT+"���������������������ŵı��У�\n"+
        "��ȡ$n"+WHT+"������������Ҫ��λ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
