//�쵶�˾���
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 80

int perform(object me,object target)
{ 
   object weapon;
   int damage,flag;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("���쵶�˾���ֻ����ս����ʹ�ã�\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("�����޵������ʹ�á��쵶�˾�����\n");
	if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("tiandao-bajue"))
    return notify_fail("��ѧ�μҵĵ������ʹ�á��쵶�˾�����\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("blade",1)<110)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("tiandao-bajue",1)<110)
    return notify_fail("����쵶�˾��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�����쵶�˾�����\n");
    
    if(me->query("perform_quest/bajue")
      &&time()-me->query_temp("perform_busy")<8)
          return notify_fail("����ʩչ���쵶�˾�����Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(me->query("perform_quest/bajue_fail")
      &&time()-me->query_temp("perform_busy")<4)
          return notify_fail("����ʩչ���쵶�˾�����Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/bajue")
      &&time()-me->query_temp("perform_busy")<3)
          return notify_fail("����ʩչ���쵶�˾�����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    
    if(me->query("perform_quest/bajue_fail")){
      damage=damage*3/4;
      flag=0;
    }
    else
    if(!me->query("perform_quest/bajue")){
     damage=damage/2;
     flag=0;
    }else flag=1;
    
    if(!flag)
    msg=HIC"$N"+HIC+"һ�С���绷�塹����$n"+HIC+"��$l�����·��������ƶ˳˷���ȥ���䲻�ܿ�����ȴ�л���\n"+
        "��ϵ�����������\n"NOR;
    else
    msg=HIC"$w"+HIC+"������գ�������������ص���������ȫ���е����洦����������������Ȼʧɫ����\n"+
        "�о���ֹ��������㣬���Խ��ͣ��������ݡ�ֻ��$w"+HIC+"�ƿն�ȥ��������ɿռ䣬ֱ��$n"+HIC+"��\n"+
        "ȴû�����κ��Ʒ�����������㵶��������$n"+HIC+"ȴ������յ�$N"+HIC+"��$w"+HIC+"�����ֵأ���Ӳƴһ;\n"+
        "�⣬������һѡ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���쵶�˾���ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("tiandao-bajue",1)<130){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ�һ���쵶��\n");
    }
    
    if(!flag)
    msg=HIG"$N"+HIG+"һ�С�����ˮ�ơ�����$n"+HIG+"����ۣ�����$w"+HIG+"����ʮ����ȴ��ϼ�����ƣ�����ˮ����Ӱ����\n"+
        "ת��������̬���\n"NOR;
    else
    msg=HIG"$N"+HIG+"��������������$n"+HIG+"��ǰ��$w"+HIG+"���������Ծ������Ѱ�Ҷ��֣���һ�������������Ϻ���\n"+
        "��֮��Ĵ��䣬��$n"+HIG+"��$l��ȥ����$N"+HIG+"��������ȫ��$w"+HIG+"����������Ȼ������\n"+
        "����������Σ���Ȼ��覣����ɾ��ס�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    
    if(!me->is_fighting())
    return notify_fail("���쵶�˾���ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("tiandao-bajue",1)<150){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������쵶��\n");
    }
    
    if(!flag)
    msg=HIG"$N"+HIG+"��ˮ�����ϵĵ�ʽ����ػ���һ���̹�ұұ��������ʯ����Ȫ��ˮ������$w"+HIG+"����\n"+
        "һ����â��ѭĳһ�������������κ������������ݵĻ��ȣ�ֱȡ$n"+HIG+"�����ǡ�ʯ����Ȫ����\n"NOR;
    else
    msg=HIG"$N"+HIG+"���Ʊ仯�����xȫ�����������ת�������޷������쵶��һ�̵�λ�á������ƽ�\n"+
        "�ǽ������˷��ˣ�ȷ����и�ɻ��ĵ�����ֻ�����ۡ�˫��һ��������$n"+HIG+"���ȷ糵����ת��\n"+
        "���ܻ�ȥ$N"+HIG+"�޼᲻�ݵ��������Ȼ���ʧ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���쵶�˾���ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("tiandao-bajue",1)<170){
    	me->set_temp("perform_busy",time());
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������쵶��\n");
    }
    
    
    if(!flag)
    msg=YEL"$N"+YEL+"����������������һ�С���Ҷ����硹ֱȡ$n"+YEL+"��$l��$w"+YEL+"�������������ȫ�޺ۼ���\n"+
        "·��Ѱ����������������$n"+YEL+"�Ĺ�����ʱ�����߽⡣\n"NOR;
    else
    msg=YEL"$N"+YEL+"��$w"+YEL+"ÿһ���־�����Ƶл��еĹ��ߣ������κ�������Ҳû����ķ�ʽ��\n"+
        "Ӧ��$n"+YEL+"�����Ĺ�����ֻ��$N"+YEL+"׷���޶����Ծ��˸�����Ų���ƣ���$N"+YEL+"����̬\n"+
        "������ô���Ϻ�ս���Ĵ��ݴ�ȣ�����ռ�������������ңƮ�ݵ���ζ�������������κ�\n"+
        "���Ա�ī������������ңƮ�ݵ���ζ��\n"NOR;
	
	COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
	    
    if(!me->is_fighting())
    return notify_fail("���쵶�˾���ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("tiandao-bajue",1)<190){
    	me->set_temp("perform_busy",time());
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������쵶��\n");
    }
    
    msg=HIY"\nֻ��৵�һ����$N"+HIY+"���ջ����е�"+weapon->query("name")+HIY+"�������´�����Ȼ��Ȼ����һ���Ӵ���ƥ�����ƽ���$n"+HIY+"��\n"NOR;
    message_vision(msg,me,target);
    
    if(!flag){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    me->set_temp("perform_busy",time());
    call_out("perform2",4,me,target,weapon,damage);
    
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
	   
    msg=HIR"ֻ��৵�һ����$w"+HIR+"�����ˣ�һ��ֻ����һ������ȥ���ݣ������������ѿ�����ĸ����£�\n"+
        "$n"+HIR+"�е�$N"+HIR+"����ʱ��$w"+HIR+"���ѻӳ������������ĳ��磬�������ɵ���������Լ���$n"+HIR+"ֻ�е�\n"+
        "�������е��������������Ʊ�$N"+HIR+"�⾪�춯�ص�һ������һ˿��ʣ��һ������������������\n"+
        "��ɱ�ĺ���ζ����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���쵶�˾���ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("tiandao-bajue",1)<210){
    	me->set_temp("perform_busy",time());
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������쵶��\n");
    }
    
    msg=WHT"$N"+WHT+"һ��������$w"+WHT+"ƽƽ���������ӭ������$n"+WHT+"��ɨ������������������κβ���������ȴ����\n"+
        "���ϳ���$n"+WHT+"ȴ������յ�$N"+WHT+"����Ԣ��������������׾���䲻���κα仯����ǧ���򻯾���\n"+
        "���У������֮��������û�о�����\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���쵶�˾���ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("tiandao-bajue",1)<230){
    	me->set_temp("perform_busy",time());
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������쵶��\n");
    }
    
    msg=WHT"$N"+WHT+"��$w"+WHT+"��Ȼ̽�����仯��ͻȻ�վ���$n"+WHT+"һʱ���飬���ζ�ʱ��$N"+WHT+"��$w"+WHT+"��ס��\n"+
        "ֻ��$N"+WHT+"һ����Ц��$w"+WHT+"��$n"+WHT+"˫�Ƽ����ֱ��ͷ���Ϸ���ֱָ��ҹ�յ�λ��������������$n"+WHT+"\n"+
        "��ͨ������֮�ܣ����������£����ѵ���$N"+WHT+"���С�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���쵶�˾���ֻ����ս����ʹ�ã�\n");
    
    if(me->query_skill("tiandao-bajue",1)<250){
    	me->set_temp("perform_busy",time());
        return notify_fail("��ĵ�����Ϊ���㣬Ŀǰֻ�ܳ������쵶��\n");
    }
    
    msg=HIG"$N"+HIG+"��$w"+HIG+"���������ƽ�еĵ������޵�ȫ�ٳ�̣�ֱ��ǰ���������$n"+HIG+"��ʸ�㼤���ȥ��ֻ��\n"+
        "$w"+HIG+"��ֱ���䣬Ѹ��������$n"+HIG+"�ľ��룬�����Ѷ�����ȫ�������֣���$n"+HIG+"���ص�һ�̣�\n"+
        "ǡ��$w"+HIG+"�����ɲ�ǡ�"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set("apply_points",0);
    me->set_temp("perform_busy",time());
    return 1;   
  
}
