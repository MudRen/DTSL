//�������� 
//��������
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 30

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage;
        
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("������������ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="hammer")
    return notify_fail("�����޴������ʩչ��������������\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("leiting-chuifa",1))
    return notify_fail("�����������������ʹ����������������\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("hammer",1)<160)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("leiting-chuifa",1)<160)
    return notify_fail("������������������ң�\n");
    if((int)me->query_skill("bihai-force",1)<150)
    return notify_fail("��ġ��̺��񹦡��������ң�\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ��������������\n");
    if(me->query("perform_quest/pili")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("����ʩչ��������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/pili")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ��������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/pili"))
    damage=damage/3;
    else
    damage=damage+damage/3;
    
    msg=HIW"$N"+HIW+"Ծ�ն�������$w"+HIW+"һת˳��һ�У���ȡ�"+HIC+"��"+HIW+"����$n"+HIW+"��$l��ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������������ֻ����ս����ʹ��!\n");
    
    msg=HIG"$N"+HIG+"�����ſ첽���ϣ�����$w"+HIG+"����������ɽ����ȡ�"+HIC+"��"+HIG+"����$n"+HIG+"��$l��ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������������ֻ����ս����ʹ��!\n");
    
    msg=HIR"$N"+HIR+"˫��һ������$w"+HIR+"����Ϊ�򣬴�ȡ�"+HIC+"��"+HIR+"����$n"+HIR+"��$l����ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������������ֻ����ս����ʹ��!\n");
    
    msg=HIB"$N"+HIB+"�������飬����$w"+HIB+"���ŷ��裬��ȡ�"+HIC+"��"+HIB+"��ֱ��$n"+HIB+"��$l��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set_temp("perform_busy",time());
    return 1;   
  
 }  

