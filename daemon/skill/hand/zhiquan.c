//��ȭӡ
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int flag=0;
     
     object weapon;
     
     if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");	
    
     weapon=me->query_temp("weapon");	
     if(weapon)
    return notify_fail("�������������ʹ�á���ȭӡ����\n");
    if(!me->is_fighting())
    return notify_fail("ֻ����ս��ʱ�ſ���ʹ�á���ȭӡ����\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("��ѧ���������ԡ����ʹ�á���ȭӡ����\n");
    if((int)me->query("max_force")<2000)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query("force")<200)
    return notify_fail("�����������ʹ�ô�����!\n");
    if((int)me->query_skill("jiuzi-zhenyan",1)<160)
    return notify_fail("��ľ�������̫���ˣ�\n");
    if((int)me->query_skill("strike",1)<160)
    return notify_fail("��Ļ����Ʒ��������ң�\n");
    
    if(time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ����ȭӡ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    me->add("force",-200);
    
    flag+=COMBAT_D->do_attack(me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ȭӡ��ֻ����ս����ʹ��!\n");
    
    flag+=COMBAT_D->do_attack(me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ȭӡ��ֻ����ս����ʹ��!\n");
    
    flag+=COMBAT_D->do_attack(me,target,0,0,2);
    
    if(flag){
       message_vision("\n$n��$N���У���ʱ���û���������Ҳʹ�������������\n",me,target);
       if(!target->is_busy())
       target->start_busy(3);
    }
    
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
