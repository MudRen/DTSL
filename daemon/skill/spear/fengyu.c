//���������
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 50

int perform(object me,object target)
{ 
   object weapon;
   int damage,flag;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("�����������ֻ����ս����ʹ�ã�\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="spear")
    return notify_fail("������ǹ�����ʹ�á������������\n");
	if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("fuying-spear"))
    return notify_fail("��ѧ��ӥǹ�����ʹ�á������������\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("spear",1)<110)
    return notify_fail("��Ļ���ǹ��̫���ˣ�\n");
    if((int)me->query_skill("fuying-spear",1)<110)
    return notify_fail("��ķ�ӥǹ���������ң�\n");
    if(me->query_skill("yanyang-dafa",1)<100)
    return notify_fail("�����������Ϊ̫���ˣ�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ���������������\n");
    
    if(me->query("perform_quest/fengyu")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ�������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/fengyu")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ�������������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/fengyu")){
     damage=damage/2;
     flag=0;
    }else flag=1;
    
   
    msg=HIY"$N"+HIY+"��$w"+HIY+"�ƻ�ǰ����ֻ�Ե��֒��ţ�ǹ��ңָ���֣����ַ����������̬���ݺÿ���\n"+
        "$N"+HIY+"���쳤Ц������$w"+HIY+"�����ݣ��������ͣ��ͣ���ǹ����ֱ��$n"+HIY+"��$l��ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����������ֻ����ս����ʹ�ã�\n");
    
    
    msg=HIG"$N"+HIG+"������ǣ���£�΢�����ư벽������$w"+HIG+"��Ϊһ����â���缲б�̣��Ƕ�֮�ǡ�ñ�$n"+HIG+"\n"+
        "�˼ʲ�ȡ�Ľ���·��Ҫ����һ�����ж��֡�$w"+HIG+"������һ�����磬�����侪�˵����ơ���$n"+HIG+"\n"+
        "֮�ܣ����ϲ���$N"+HIG+"�����Թ�������ʱ�������յ���˾��������������������ǹ�ƻ�Ȼ��\n"+
        "�ɡ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����������ֻ����ս����ʹ�ã�\n");
   
    
    msg=WHT"�̶̵ľ����ڣ�$N"+WHT+"��ǹ��ȴ�Ǳ仯��ǧ��ÿһɲ�Ƕ�����΢���ĸı䣬����$N"+WHT+"�仯��\n"+
        "���һǹ���������罫$n"+WHT+"��ȫ���֣���������ǿ���ֲ��ֲ���΢��Ķ���ʹ�˷���ʤ����\n"+
        "���޿ɵ���\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
       
    if(!flag){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    
    call_out("perform2",3,me,target,weapon,damage);
    me->set_temp("perform_busy",time());
    return 1;   
  
}

int perform2(object me,object target,object weapon,int damage)
{ 
        string msg;
        
        if(!me) return 1;
        if(!target||!living(target)){
         me->set_temp("perform_busy",time());
         return 1;
        }
        me->set_temp("perform_busy",time());
        if(!weapon||me->query_temp("weapon")!=weapon)
        return 1;
        if(me->is_busy())
        return 1;
  
        if(!me->is_fighting(target))
	   return 1;
	   
    msg=MAG"$N"+MAG+"һ��Ц��ǹ��չ������գ�۵ĸ��ټ䣬�����̳���ǹ��ÿһǹ�ĽǶȾ����$n"+MAG+"�ķ�Ӧ\n"+
        "�����б仯��������ٱ��һʱ��ǧǹӰ����$n"+MAG+"��ȫ�������С�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����������ֻ����ս����ʹ�ã�\n");
      
    msg=HIR"$N"+HIR+"������Ⱪ�֣����е�$w"+HIR+"ٿ�ش̳����ó�����ǹӰ������$n"+HIR+"������Ҳ����������$n"+HIR+"ֻ��\n"+
        "����ǰһ����һ����ȥ����ֻ��һƬǹ��������ǵض������·���ؼ�������һʱ֮\n"+
        "�䣬�����ɥ�����޷����С�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
        
    me->set_temp("perform_busy",time());
    return 1;   
  
}
