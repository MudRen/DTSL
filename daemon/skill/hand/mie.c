//������ȭ����������
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
		return notify_fail("����������ֻ����ս����ʹ��!\n");
   if(weapon)
    return notify_fail("�������������ʹ�á��������񡹣�\n");
    if(!me->query_skill("linglong-yuquan",1))
    return notify_fail("��ѧ��������ȭ�����ʹ�á��������񡹣�\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("cuff",1)<110)
    return notify_fail("��Ļ���ȭ��̫���ˣ�\n");
    if((int)me->query_skill("linglong-yuquan",1)<110)
    return notify_fail("��ġ�������ȭ���������ң�\n");
    if((int)me->query_skill("tianmo-dafa",1)<100)
    return notify_fail("��ġ���ħ�󷨡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ���������񡹣�\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points")/2;
    
    msg=HIC"$N"+HIC+"����ӯ��ȭ������������������̬���纬����Ů����ͬʱ����\n"+
        "������������$n"+HIC+"��$l����ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����������ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"�����ݳ�һ˿Ц�⣬������ȭӰ��$n"+HIY+"�����������ƹ����أ���϶����Ĺ�����\n"+
        "ٿ��$n"+HIY+"��ǰ�ֳ������ǵ㣬ÿһ�㶼�ƺ���������������ÿһ�㶼��ˮ�㲻����\n"+
        "�������ϵ��ǿգ��ڱ仯�������Ծߺ㳣�����ζ����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����������ֻ����ս����ʹ��!\n");
    
    msg=HIG"$N"+HIG+"�ɿ�ת�����������������ŵ���ת������˫ȭ�ƺ�֯��������覵�Բ����\n"+
        "��$n"+HIG+"�������У���ʹ$n"+HIG+"������֪�ù��δ������θо���\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
