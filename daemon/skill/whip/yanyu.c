//��������
//��Ϊ�б����ĸ����˺������������
//�˺�Ӧ�õ�һЩ��

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -200


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
   return notify_fail("���������ʡ�ֻ����ս����ʹ�ã�\n");
   if(!weapon)
    return notify_fail("�������������ʹ�á��������ʡ���\n");
   if(weapon->query("skill_type")!="whip")
    return notify_fail("���ñ��ӣ����ʹ�á��������ʡ���\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("shuiyun-xiufa",1))
    return notify_fail("��ѧ��ˮ���䷨�����ʹ�á��������ʡ���\n");
    if(me->query("apply_points")<=0)
    return notify_fail("������Ʋ��㣬�޷�ʹ�á��������ʡ���\n");
    
    if((int)me->query("max_force")<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("whip",1)<160)
    return notify_fail("��Ļ����޷�̫���ˣ�\n");
    if((int)me->query_skill("shuiyun-xiufa",1)<160)
    return notify_fail("��ġ�ˮ���䷨���������ң�\n");
    if((int)me->query_skill("bihai-force",1)<150)
    return notify_fail("��ġ��̺��񹦡��������ң�\n");
    
    if(me->query("perform_quest/yanyu")
       &&time()-me->query_temp("perform_busy")<8)
       return notify_fail("����ʩչ���������ʡ���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    if(!me->query("perform_quest/yanyu")
       &&time()-me->query_temp("perform_busy")<4)
       return notify_fail("����ʩչ���������ʡ���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/yanyu"))
    damage=damage/2;
    else damage=damage*2;
  
    msg=WHT"$N"+WHT+"һ��һ����$w"+WHT+"�����������Ż����������������������ˮ�����˿����Ŀ�������$w"+WHT+"��\n"+
        "�ƺ����������˵����㣬ֻ��৵�һ����$w"+WHT+"����$n"+WHT+"��$l��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
   
    if(!me->is_fighting())
    return notify_fail("���������ʡ�ֻ����ս����ʹ�ã�\n");
    
    msg=HIC"$N"+HIC+"ˮ���䷨�ȳ���$w"+HIC+"���ӣ��������಻����ͬ����������ͻȻ������Ц��Ц�����н�����\n"+
        "�������������ư��$w"+HIC+"ʹ�������������$n"+HIC+"������֡�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
   if(!me->is_fighting())
    return notify_fail("���������ʡ�ֻ����ս����ʹ�ã�\n");
    
    msg=HIG"$N"+HIG+"���е�$w"+HIG+"����ͻȻ�仯�����׺�������״���֣�ٿ�ر�Ϊ����������ޱȣ�$w"+HIG+"�Ϸ�\n"+
        "�����������$n"+HIG+"һ����֪������ͭǽ���ڣ����Ǳ�$w"+HIG+"���У�Ҳ�����һ��顣\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(objectp(target)&&random(10)>6){
    	msg=WHT"\n$N"+WHT+"�ڻ��֮���ƺ����������ǣ�������Ȼ���ң�\n\n"NOR;
    	message_vision(msg,target);
    	target->start_busy(random(5));
    }
    
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
