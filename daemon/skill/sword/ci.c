//��Ӱͻ�̡�

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 100 //!!!�������

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int flag=0,damage;
    
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("����Ӱͻ�̡�ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("�����޽������ʹ�á���Ӱͻ�̡���\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("yingzi-jianfa"))
    return notify_fail("��ѧ��Ӱ�ӽ��������ʹ�á���Ӱͻ�̡���\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("sword",1)<110)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("yingzi-jianfa",1)<110)
    return notify_fail("��ġ�Ӱ�ӽ������������ң�\n");
    if((int)me->query_skill("dodge",1)<100)
    return notify_fail("��ġ������Ṧ���������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ����Ӱͻ�̡���\n");
    
    if(me->query("vocation")!="ɱ��")
    return notify_fail("ֻ��ɱ�ֲ���ʩչ����Ӱͻ�̡���\n");
    
    if(me->query("job_office_number/ɱ������")>=1000)
     flag=1;
    
    if(flag
      &&time()-me->query_temp("perform_busy")<7)
       return notify_fail("����ʩչ����Ӱͻ�̡���Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!flag
      &&time()-me->query_temp("perform_busy")<3)
       return notify_fail("����ʩչ����Ӱͻ�̡���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    if(flag) damage=me->query("apply_points");
    else
    damage=me->query("apply_points")/2;
    
    msg=HIB"$n"+HIB+"���������ݽ�һ�ֽ����޿ɿ��ܵľ��������ǧ�ٹ���ֵ����������ְ�$n"+HIB+"��ǰ����\n"+
        "��ȴֱѹ���������м��ɺ������ת������������������˴�ŭ����ӿ�������У�ʹ��\n"+
        "���������ѳֵ�������\n"NOR;    
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
  
    if(!me->is_fighting())
    return notify_fail("����Ӱͻ�̡�ֻ����ս����ʹ��!\n");
    
    msg=HIB"$n"+HIB+"��Ҳ���룬���̾ۼ���ȫ��������������ͬʱ�����˷�������ȥ�� һʱ�䣬$n"+HIB+"ֻ\n"+
        "�ܼ���һ����Ӱ�ӡ�һ�㽣â������$n"+HIB+"��ǰ�����޼᲻�ݵĽ�����͸������������ʹ\n"+
        "$n"+HIB+"������ֹ��ȫ���������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����Ӱͻ�̡�ֻ����ս����ʹ��!\n");
    
    msg=BLU"$n"+BLU+"��ǰ���е�㽣â������������ʹ$n"+BLU+"��Ŀ��ä��ֻ�ܴ�ƾ�о�������Ӧ��ġ�ؽ�â��\n"+
        "ʢ������˷����Ǻ�Х�Ľ�Ӱâ�⣬��ʵ�Ѳ⡣$n"+BLU+"�е��н�����һ��ճ��֮�����Է���\n"+
        "�������߰㸽��$n"+BLU+"����Χ������$n"+BLU+"��$l��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
   
   me->set_temp("perform_busy",time());
    return 1;   
  
}  

