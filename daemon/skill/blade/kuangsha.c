//��ɳ��
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -100

int perform(object me,object target)
{ 
   object weapon;
   int damage,flag;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("����ɳ��ֻ����ս����ʹ�ã�\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("�����޵������ʹ�á���ɳ����\n");
	if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("kuangsha-daofa"))
    return notify_fail("��ѧ��ɳ�������ʹ�á���ɳ����\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("blade",1)<110)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("kuangsha-daofa",1)<110)
    return notify_fail("��Ŀ�ɳ�����������ң�\n");
    if(me->query_skill("yanyang-dafa",1)<100)
    return notify_fail("�����������Ϊ̫���ˣ�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ������ɳ����\n");
    
    if(me->query("perform_quest/kuangsha")
      &&time()-me->query_temp("perform_busy")<10)
          return notify_fail("����ʩչ����ɳ��������Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/kuangsha")
      &&time()-me->query_temp("perform_busy")<5)
          return notify_fail("����ʩչ����ɳ��������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/kuangsha")){
     damage=damage/2;
     flag=0;
    }else flag=1;
    
   
    msg=HIY"һ����Х��$N"+HIY+"�����ҵ�����������$n"+HIY+"��ת��ȥ������֯����â���䣬���ؼ汸��������\n"+
        "����ľ�������$N"+HIY+"Ϊ������ɳĮ����Ŀ񱩷�ɳ�㣬����$N"+HIY+"���Ƚ������������֮����$n"+HIY+"\n"+
        "Ϯȥ������������$N"+HIY+"��ÿ����ת�ٶȶ���΢��Ĳ��죬��������Ԥ������$N"+HIY+"����Ϯ��ľ�\n"+
        "ȷʱ�䡣\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ɳ��ֻ����ս����ʹ�ã�\n");
    
    
    msg=HIR"����Ŀ�����ֹͣ���������ռŵ���û�а�η��ãã��Į������������������һ������\n"+
        "��ֹ����������������ҹ��ʱ�����ţ�����ȫ��������Ǭ��ɳĮ�����������ȶ�ȴ������\n"+
        "����$N"+HIR+"�������ף�����һ�����յ�����$w"+HIR+"��ħ���������ǰ�����Լ�����������ַ���\n"+
        "���浶�ߣ���$n"+HIR+"��ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ɳ��ֻ����ս����ʹ�ã�\n");
   
    
    msg=HIG"$N"+HIG+"һ����Х������һ�䣬�ó���ɳ������ĵ��ˣ�������$n"+HIG+"��ȥ�����ǿ�ɳ����еġ���\n"+
        "ɳ������$n"+HIG+"���˿̷�������ᵽ$N"+HIG+"�ľ��칦�������������ڿ���ŭ�֮�У����˹���������\n"+
        "�������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
       
    if(!flag){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    me->set_temp("perform_busy",time());
    call_out("perform2",2,me,target,weapon,damage);
    
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
	   
    msg=MAG"$w"+MAG+"����ջ���һ����������ζ�������˰�����Ĺ켣���仯����ĳ�$n"+MAG+"��������������\n"+
        "һ����ȴ��ʮ��������Ĳ�����ɣ�ÿ������ʱ��͹����ĽǶȶ��о�΢��ת�䣬�ͳ�\n"+
        "���������Ϊ���ܱ�ǽ�ѱڵ������������������Ρ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("����ɳ��ֻ����ս����ʹ�ã�\n");
      
    msg=WHT"$N"+WHT+"˫Ŀ����ʢ����������ȫ�����Ƿ��ͬʱ�߷���ɳ����$w"+WHT+"�������������������\n"+
        "��ɳ�����׺��Ĵ�Į�����г���ϸɰ�����������ɳ����$n"+WHT+"���ʹ����$N"+WHT+"ͦ�����ɰ�\n"+
        "����ΰ���Σ�ȷ�в�����ɽ��Ԩͤ���ŵ����ƣ����������硣$n"+WHT+"��ʱ����Ǭ�����ȵĺ���\n"+
        "�о���������������ɳ�����ܵ�����ʧ��С�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
        
    me->set_temp("perform_busy",time());
    return 1;   
  
}
