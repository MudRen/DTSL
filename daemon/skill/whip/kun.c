//���α޷�
//��������

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 50


int perform(object me,object target)
{ 
    object weapon;
    int damage,flag=0;
    string msg;
    
    weapon=me->query_temp("weapon");
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
    
   if(!me->is_fighting())
   return notify_fail("������������ֻ����ս����ʹ�ã�\n");
   if(!weapon)
    return notify_fail("�������������ʹ�á�������������\n");
   if(weapon->query("skill_type")!="whip")
    return notify_fail("���ñ��ӣ����ʹ�á�������������\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("feiwo-whip",1))
    return notify_fail("��ѧ[���α޷�]���ʹ�á�������������\n");
    if(me->query("apply_points")<=0)
    return notify_fail("������Ʋ��㣬�޷�ʹ�á�������������\n");
    
    if((int)me->query("max_force")<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("whip",1)<110)
    return notify_fail("��Ļ����޷�̫���ˣ�\n");
    if((int)me->query_skill("feiwo-whip",1)<110)
    return notify_fail("��ġ����α޷����������ң�\n");
    if((int)me->query_skill("yanyang-dafa",1)<100)
    return notify_fail("��ġ������󷨡��������ң�\n");
    
    if(me->query("perform_quest/kun")
     &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ��������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    if(!me->query("perform_quest/kun")
     &&time()-me->query_temp("perform_busy")<7)
       return notify_fail("����ʩչ��������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/kun"))
    	damage=damage/2;//���û�����⡣
    else
    	damage=damage*2;
    
    msg=HIG"$N"+HIG+"˫Ŀ�����ʢ��$w"+HIG+"�����������һ��â��������ȫ�������˵�$n"+HIG+"�����ȥ������\n"+
        "������Ҫ����һ�ߡ�$N"+HIG+"ս��֮��������ʽ�ĺ������ַ�����£���ʹ����Ŀ�о���\n"NOR;   
    
    flag=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    
    if(!me->is_fighting())
    return notify_fail("������������ֻ����ս����ʹ�ã�\n");

    msg=HIY"$N"+HIY+"ȫ��һ���������˰벽���������ɭ����ɫ���ó�ǧ�ػ�Ӱ����$w"+HIY+"����չ�����ޣ���\n"+
        "$n"+HIY+"ȫ������������н��Ǿ�����׵ľ�����\n"NOR;    
        
    flag+=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������������ֻ����ս����ʹ�ã�\n");
    
    if(!me->query("perform_quest/kun")){
      if(flag){
      	msg="\n$n��$N���У�����һ���ж���ʱ�ٻ��ˣ���\n";
      	message_vision(msg,me,target);
      	target->start_busy(3);      	
      }
      me->set_temp("perform_busy",time());
      return 1;
    }
    
    msg=HIR"$N"+HIR+"��������һ�飬$w"+HIR+"������𣬵�ʱɭ�����ˣ�������$n"+HIR+"��ȥ��Ҳ��֪$N"+HIR+"ʹ��ʲô�ַ���\n"+
        "$w"+HIR+"����һ�Ķ��Ѽ�ɳ��������������ƿ�������������˸�Ȧ����$n"+HIR+"��$l��ȥ���ַ���\n"+
        "��֮����\n"NOR;
    
    flag+=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������������ֻ����ս����ʹ�ã�\n");
    
    if(flag){
      	msg="\n$n��$N���У�����һ���ж���ʱ�ٻ��ˣ���\n";
      	message_vision(msg,me,target);
      	target->start_busy(4);      	
    }
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
