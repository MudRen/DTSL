//�ݺᡣ
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -125

int perform(object me,object target)
{ 
   object weapon;
   int damage,flag;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("���ݺ᡹ֻ����ս����ʹ�ã�\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("�����޵������ʹ�á��ݺ᡹��\n");
	if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("badao"))
    return notify_fail("��ѧ�Ե��������ʹ�á��ݺ᡹��\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("blade",1)<110)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("badao",1)<110)
    return notify_fail("��İԵ������������ң�\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�����ݺ᡹��\n");
    
    if(me->query("perform_quest/badao")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("����ʩչ���ݺ����¡���Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/badao")
      &&time()-me->query_temp("perform_busy")<8)
      return notify_fail("����ʩչ���ݺ����¡���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/badao")){
     damage=damage/2;
     flag=0;
    }else flag=1;
    
    
    msg=HIR"$N"+HIR+"һ����Ц�����ְγ�����$w"+HIR+"�����������ţ�$w"+HIR+"��˸���ԣ����Ʒ�ӳ�����ϵ���ɫ��\n"+
        "���һվ����¶��һ�����̺��������ƺͳ�����Ȼ�ĺ������ʣ�����ǿ�����׵�ɱ����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ݺ᡹ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("badao",1)<130){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ�һ���ݺᣡ\n");
    }
    
    msg=HIY"$N"+HIY+"ǰ��һ����$w"+HIY+"�ɺ�ڱ��ֱָ��ǿ���ɭ�����ǵĵ�����$n"+HIY+"��ӿ����������ӿ���\n"+
        "�����������۳�ɳ����ɱ��ǧ������֮���׳���黳��һ����Х����ض��𣬼���\n"+
        "�������$n"+HIY+"��ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ݺ᡹ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("badao",1)<150){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������ݺᣡ\n");
    }
    
    msg=HIG"$N"+HIG+"΢һ��ͷ���͵ؼ���ǰ�壬����$w"+HIG+"����һ�����磬��$n"+HIG+"�����ȥ�������׶�֮����\n"+
        "��˴���ʹ�˸е���һ���ۼ���$N"+HIG+"ȫ��������$n"+HIG+"������ѷ�Ļ���һ����ɷֳ�ʤ\n"+
        "�ܡ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ݺ᡹ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("badao",1)<170){
    	me->set_temp("perform_busy",time());
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������ݺᣡ\n");
    }
    
   
    if(!flag){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    me->set_temp("perform_busy",time());
    call_out("perform2",3,me,target,weapon,damage);
    
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
	   
    msg=WHT"$N"+WHT+"һ����Х����ʱ�ų����������ϣ���̨��Ⱦһ����$w"+WHT+"�ɿ�ת�����Ʊ������̩\n"+
        "ɽ�����������������ޱȵľٵ��������ƺ��ذѷ�Բ�����ڵĿ���ȫ����ˣ�����\n"+
        "��������$n"+WHT+"��������ƣ�ʹ$n"+WHT+"�������ҽ��������˺�Ҳ�������ܡ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ݺ᡹ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("badao",1)<190){
    	me->set_temp("perform_busy",time());
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������ݺᣡ\n");
    }
    
    msg=HIR"$N"+HIR+"���һ�����˾�һ������$w"+HIR+"����ʱ����һ�ֽ�������֮����$w"+HIR+"�������º�â������\n"+
        "ҫ����Ŀ��$N"+HIR+"˫�ֱ�����ٿ����������̤�����Ĳ�������$n"+HIR+"����ʱ��ȫ��һ����\n"+
        "����������磬˲�Ǽ�����$n"+HIR+"ͷ������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ݺ᡹ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("badao",1)<210){
    	me->set_temp("perform_busy",time());
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������ݺᣡ\n");
    }
    
    msg=HIY"$N"+HIY+"��$w"+HIY+"�վ���ͷ�������չ��·�������Ŀѣ���Ե�������˫Ŀ�����磬����$n"+HIY+"����\n"+
        "�ؿ��һ����ͬһʱ�䣬$w"+HIY+"����һ����âѣĿ�����˲ʺ磬Ѹ���������û�˿ɿ���\n"+
        "�����ٶȣ�������$n"+HIY+"������ȥ����������쭣�ȴ�����������$n"+HIY+"����Ȼ�о�������\n"+
        "֮����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
        
    me->set("apply_points",0);
    me->set_temp("perform_busy",time());
    return 1;   
  
}
