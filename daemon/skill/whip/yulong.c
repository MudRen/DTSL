//����Ԧ��
//��Ϊ�б����ĸ����˺������������
//�˺�Ӧ�õ�һЩ��

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 50

void show_msg(object me,object victim)
{
    string str;
    
     if (userp(victim)&&
          (victim->query("eff_kee")<0 || 
          !living(victim) 
          )
        )   {
          str="��˵"+victim->name()+""HIM"����"+me->name()+""HIM"��"HIR"����Ԧ��"HIM"֮�£�������Ѫ���죡"NOR;
                        message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
     }
     return;
}

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
   return notify_fail("������Ԧ����ֻ����ս����ʹ�ã�\n");
   if(!weapon)
    return notify_fail("�������������ʹ�á�����Ԧ������\n");
   if(weapon->query("skill_type")!="whip")
    return notify_fail("���ñ��ӣ����ʹ�á�����Ԧ������\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("tianmo-dai",1))
    return notify_fail("��ѧ[��ħ��]���ʹ�á�����Ԧ������\n");
    if(me->query("apply_points")<=0)
    return notify_fail("������Ʋ��㣬�޷�ʹ�á�����Ԧ������\n");
    
    if((int)me->query("max_force")<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("whip",1)<160)
    return notify_fail("��Ļ����޷�̫���ˣ�\n");
    if((int)me->query_skill("tianmo-dai",1)<160)
    return notify_fail("��ġ���ħ�����������ң�\n");
    if((int)me->query_skill("tianmo-dafa",1)<150)
    return notify_fail("��ġ���ħ�󷨡��������ң�\n");
    
    if(time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ������Ԧ������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/yulong"))
    damage=damage/2;//���û�����⡣
    /*
    if(!me->query_temp("apply/yulong_cloth"))
    damage=damage-damage/3;//���û��ָ�����·���
    */

    msg=HIC"$N"+HIC+"ͻȻ����$n"+HIC+"ʹ��̾Ϊ��ֹ��һ�䣬����δ����$n"+HIC+"����˫����ʱ�����ػ�Ϊ����\n��Ӱ����ʵ�ѷ֡�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������Ԧ����ֻ����ս����ʹ�ã�\n");
    
    
    msg=WHT"$N"+WHT+"$w���س��˰��ɣ�������ɳ�һ����˿�����ȴ�����$n"+WHT+"����֮�䣬���ս�ʱ��\n�ѽ�$n"+WHT+"һ���ָ���һ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������Ԧ����ֻ����ս����ʹ�ã�\n");
    
    
    msg=HIG"$N"+HIG+"�������������غ���$n"+HIG+"һ�ۣ����ź��ƿ�ȥ���ϵ�$n"+HIG+"���ļ�����ȫ�޷���֮����\n$N"+HIG+"��˿��ң����$n"+HIG+"�Ĵ�ײ����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("������Ԧ����ֻ����ս����ʹ�ã�\n");
    
  
    msg=HIR"$N"+HIR+"һ����һ������ħ�澢��͸��$w"+HIR+"����$n"+HIR+"��Ӳ���������$n"+HIR+"һ�ڿ���Ѫ�������\n"+
        "��������ܰ����ɼ�������ֱײ��ȫ��$N"+HIR+"�������龰�������������˲�����á�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set_temp("perform_busy",time());
    show_msg(me,target);
    return 1;   
  
}  
 
