//���Ρ�

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50 //��pfm �˺��ߣ�����Ҳ����

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage,flag;
    
    flag=0;
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("�����Ρ�ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("�����޽������ʹ�á����Ρ���\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("piaomeng-jianfa",1))
    return notify_fail("��ѧ��Ʈ�ν��������ʹ�á����Ρ���\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("sword",1)<160)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("piaomeng-jianfa",1)<160)
    return notify_fail("��ġ�Ʈ�ν������������ң�\n");
    if((int)me->query_skill("bihai-force",1)<150)
    return notify_fail("��ġ��̺��񹦡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�����Ρ���\n");
    if(me->query("perform_quest/duomeng")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ�����Ρ���Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/duomeng")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ�����Ρ���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/duomeng"))
    damage=damage/2;
    else damage=damage*2;
    
    msg=WHT"$N"+WHT+"��$w"+WHT+"����һ���׹�ת����֣���һȦȦ�������Ƽ��ҷ���������İ������֡�����\n"+
        "��ɫ����֮�У��ǹ�ϼΪ֮ʧɫ����ʧ��$n"+WHT+"���ɵ�Ϊ֮ɫ�䣡\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����Ρ�ֻ����ս����ʹ��!\n");
    
    msg=YEL"$N"+YEL+"��$n"+YEL+"�վ�һ�Ӵ���ɲ�ǣ���ɫ���ֻ���������$w"+YEL+"����ɫ��������ɴ����ʫ��\n"+
        "���Ρ��硭�������������һ���������� \n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����Ρ�ֻ����ս����ʹ��!\n");
        
    msg=MAG"$N"+MAG+"����$w"+MAG+"���ص�������������һƬ��������Ӱ����$n"+MAG+"�����������͵�Ҫ����$n"+MAG+"ʱ������\n"+
        "ͻȻ��ʢ����Ӱ��Ȼ��������Ϊ����ͨͨ��һ����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(objectp(target)&&random(10)>6){
    	msg=YEL"\n$N"+YEL+"��Ϣһ�ң�������Ȼ�ٻ������ɵô�ʧɫ��\n\n"NOR;
    	message_vision(msg,target);
    	target->start_busy(random(3));
    }
    
   me->set_temp("perform_busy",time());
    return 1;   
  
}  

