//�ٻ���
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -100

int perform(object me,object target)
{ 
   object weapon;
   int damage;
   string msg;
   
   weapon=me->query_temp("weapon");
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   
   if(!me->is_fighting())
   return notify_fail("���ٻ���ֻ����ս����ʹ��!\n");
   if(weapon)
    return notify_fail("�������������ʹ�á��ٻ�����\n");
    if(!me->query_skill("baihua-zhang",1))
    return notify_fail("��ѧ���ٻ��ơ����ʹ�á��ٻ�����\n");
    if((int)me->query("max_force")<700)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query_skill("strike",1)<70)
    return notify_fail("��Ļ����Ʒ�̫���ˣ�\n");
    if((int)me->query_skill("baihua-zhang",1)<70)
    return notify_fail("��ġ��ٻ��ơ��������ң�\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ���ٻ�����\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ���ٻ�����Ҫ������������֧�֣�����Ϊ������������У�\n");
   
    damage=me->query("apply_points")/2;
    
    msg=HIC"$N"+HIC+"����ƽ�ѣ��������ŵ�������һ�������͵س�$n"+HIC+"ײȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ٻ���ֻ����ս����ʹ��!\n");
    
    msg=HIC"$N"+HIC+"����������һ���������벻���ĽǶȳ�$n"+HIC+"��$l����ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ٻ���ֻ����ս����ʹ��!\n");
    
    msg=YEL"$N"+YEL+"������Ƹ��ϣ�˲��û���÷��֮�Σ�����·��$n"+YEL+"��$l����ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
  
    me->set_temp("perform_busy",time());
      
    return 1;   
  
}  
 
