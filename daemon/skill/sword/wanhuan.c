//ǧ����á�
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -100

void show_msg(object me,object victim)
{
    string str;
    
     if (userp(victim)&&
          (victim->query("eff_kee")<0 || 
          !living(victim) 
          )
        )   {
          str="��˵"+victim->name()+""HIM"����"+me->name()+""HIM"��"HIY"ǧ��ͭ��"HIM"֮�£���������Ц�ݣ��ֲ��쳣��"NOR;
                        message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
     }
     return;
}

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
	   return notify_fail("��ǧ����á�ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("�����޽������ʹ�á�ǧ����á���\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("qianbian-tongxiao"))
    return notify_fail("��ѧ��ǧ��ͭ�������ʹ�á�ǧ����á���\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("sword",1)<160)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("qianbian-tongxiao",1)<160)
    return notify_fail("��ġ�ǧ��ͭ�����������ң�\n");
    if((int)me->query_skill("tianmo-dafa",1)<150)
    return notify_fail("��ġ���ħ�󷨡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ��ǧ����á���\n");
    if(time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ��ǧ����á���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/wanhuan"))
    damage=damage/2;
    
    msg=HIC"$N"+HIC+"��$w"+HIC+"����������ƿ�Х������ͷ�ϻ���һ����һ����Ȧ�ӣ�\n"+
    "ÿ����Ȧ��$w"+HIC+"������������֮���ۡ�������һ˲��˲���ƿ�$n"+HIC+"������������¡�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��ǧ����á�ֻ����ս����ʹ��!\n");
    
    msg=YEL"$N"+YEL+"�����������ͨ��$w"+YEL+"����ʱ�������ˡ���һ����$n"+YEL+"����ȫ��һ��\n"+
    "�����ƵУ�ȷʵ����漫��ȴ�ֹ���ǳ���\n"NOR;
    
    flag = COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��ǧ����á�ֻ����ս����ʹ��!\n");
    
    if(flag){
       msg=HIR"\n$N"+HIR+"��̤�沽�����β��ϱ仯��ٿ��$w"+HIR+"�����ָֻ$n"+HIR+"ü�ģ������򵥣�\n"+
       "$w"+HIR+"ȴ������ͬ���������ĹŹ�������$n"+HIR+"��ʱ����ȫ����\n\n"NOR;
       msg=replace_string(msg,"$w",weapon->name());
       message_vision(msg,me,target);
       target->set("apply_points",target->query("apply_points")/5);
    }
    
    msg=HIR"$N"+HIR+"��������$w"+HIR+"��ֻ��$w"+HIR+"��ң����$N"+HIR+"�����Ƶģ�ңң�Ļ���$n"+HIR+"��$N"+HIR+"����һ�����գ�\n"+
        "��$n"+HIR+"��Χ���Ź켣����Ȧ�ӵ�$w"+HIR+"���������»ص�$N"+HIR+"�����У����ˇRĿ���ࡣ \n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
   me->set_temp("perform_busy",time());
   show_msg(me,target);
    return 1;   
  
 }  

