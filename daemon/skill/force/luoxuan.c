//��������

#include <ansi.h>

inherit SSERVER;

int exert(object me,object target)
{ 
    
    int flag;
    
    flag=0;
    
   if(!me->is_fighting())
		return notify_fail("������������ֻ����ս����ʹ��!\n");
   if(target==me)
   return notify_fail("������������ֻ�ܶԱ���ʹ�á�\n");   
   if(!me->is_fighting(target))
   return notify_fail("�ⲻ����ս����Ŀ�꣡\n");
    if(!me->query_skill("changsheng-jue",1))
    return notify_fail("��ѧ�������������ʹ�á�������������\n");
    if(!me->query("force_quest/csj_ok"))
    return notify_fail("�������޷�ʩչ��������������\n");
    if(time()-me->query_temp("exert_csj_busy")<20)
    return notify_fail("���������㣬�޷�ʩչ��������������\n");
    
    if((int)me->query("max_force")<2000)
    return notify_fail("���������Ϊ̫���ˣ�\n");
    
       if((int)me->query("force")<300)
    return notify_fail("�����������ʹ�ô�����!\n");
    
    me->add("force",-300);
    
    flag+=COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0,2);
    if(objectp(target))
    flag+=COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0,2);
    if(objectp(target))
    flag+=COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0,2);
    
    if(flag&&objectp(target)){
        target->set_temp("csj_skill_damage",me->query_skill("changsheng-jue",1));
        target->set_temp("csj_damage_time",time());
    }
    
    me->set_temp("exert_csj_busy",time());
    return 1;   
  
}  
 