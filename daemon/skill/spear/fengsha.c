//��ӥǹ��
//�����ɳ

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50


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
   return notify_fail("�������ɳ��ֻ����ս����ʹ�ã�\n");
   if(!weapon)
    return notify_fail("�������������ʹ�á������ɳ����\n");
   if(weapon->query("skill_type")!="spear")
    return notify_fail("������ǹ�����ʹ�á������ɳ����\n");
   if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("fuying-spear",1))
    return notify_fail("��ѧ��ӥǹ�����ʹ�á������ɳ����\n");
    if(me->query("apply_points")<=0)
    return notify_fail("������Ʋ��㣬�޷�ʹ�á������ɳ����\n");
    
    if((int)me->query("max_force")<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("spear",1)<110)
    return notify_fail("��Ļ���ǹ��̫���ˣ�\n");
    if((int)me->query_skill("fuying-spear",1)<110)
    return notify_fail("��ġ���ӥǹ�����������ң�\n");
    if((int)me->query_skill("yanyang-dafa",1)<100)
    return notify_fail("��ġ������󷨡��������ң�\n");
    
    if(me->query("perform_quest/fengsha")
    &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ�������ɳ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    if(!me->query("perform_quest/fengsha")
    &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ�������ɳ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/fengsha"))
    damage=damage/2;//���û�����⡣
    
    msg=HIY"һ��ֻ����һ������ȥ���ݣ������������ѿ�����ĸ����£�$n"+HIY+"�е�$N"+HIY+"����ʱ��$w"+HIY+"����\n"+
        "�̳������������ĳ��磬�������ɵ���գ�����$n"+HIY+"��$n"+HIY+"�е��������е���������������\n"+
        "���⾪�춯�ص�һ������һ˿��ʣ��һ��������������������ɱ�ĺ���ζ����\n"NOR;   
    
    flag=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    
    if(!me->is_fighting())
    return notify_fail("�������ɳ��ֻ����ս����ʹ�ã�\n");

    msg=HIR"$N"+HIR+"���ֱͦ��ǣ�ȫ�������޷��Զ�����̬����������Σ���$n"+HIR+"��Ⱥ���ѷɫ��һ��\n"+
        "�����������������¾����������κ����ݵ�����仯��ȴ���Ǻ���α�ٵ�һǹ��$n"+HIR+"��\n"+
        "$l����ȥ��\n"NOR;    
     
    flag+=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�������ɳ��ֻ����ս����ʹ�ã�\n");
    
    if(!me->query("perform_quest/fengsha")){
      if(flag){
      	msg="\n$n��$N���У�����һ���ж���ʱ�ٻ��ˣ���\n";
      	message_vision(msg,me,target);
      	target->start_busy(3);      	
      }
      me->set_temp("perform_busy",time());
      return 1;
    }
    
    msg=HIG"$N"+HIG+"ʹ��ʵ������ң�Ƶ��������������ƶ�$n"+HIG+"���������κ���в������ÿһ���ַ�������¯\n"+
        "���ࡢ�����˻��ķ�ӥǹ������һ����Զ���е��ˣ�֯�����ζ���ʵ�������������˿��\n"+
        "��ÿһ������$n"+HIG+"���潻���һ�̻������������۷壬����$n"+HIG+"����һ����\n"NOR;
    
    flag+=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�������ɳ��ֻ����ս����ʹ�ã�\n");
    
    if(flag){
      	msg="\n$n��$N���У�����һ���ж���ʱ�ٻ��ˣ���\n";
      	message_vision(msg,me,target);
      	target->start_busy(5);      	
    }
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
