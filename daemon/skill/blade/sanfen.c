//��Ե���
//���ֹ�һͳ��
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -100

int perform(object me,object target)
{ 
   object weapon;
   int damage;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
	   return notify_fail("�����ֹ�һͳ��ֻ����ս����ʹ�ã�\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("�����޵������ʹ�á����ֹ�һͳ����\n");
	if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("wuba-daofa",1))
    return notify_fail("��ѧ��Ե������ʹ�á����ֹ�һͳ����\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("blade",1)<160)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("wuba-daofa",1)<160)
    return notify_fail("�����Ե����������ң�\n");
    if(me->query_skill("jiuxuan-dafa",1)<150)
    return notify_fail("��ľ�������Ϊ̫���ˣ�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�������ֹ�һͳ����\n");
    
    if(me->query("perform_quest/sanfen")
      &&time()-me->query_temp("perform_busy")<10)
          return notify_fail("����ʩչ�����ֹ�һͳ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/sanfen")
      &&time()-me->query_temp("perform_busy")<5)
          return notify_fail("����ʩչ�����ֹ�һͳ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/sanfen"))
     damage=damage/2;
            
    msg=HIR"$N"+HIR+"���̰�$w"+HIR+"�����ڳ���������������仯��������ɷ��������һ�ֺ�ΰ׳������\n"+
        "�ǣ����뵶���Ϊһ�����³���бָ���ϣ����������ȴ���ɲ�������ʯ�����ڷ�\n"+
        "�ڣ��������Ϊһ�塣\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ֹ�һͳ��ֻ����ս����ʹ�ã�\n");
       
    msg=YEL"$N"+YEL+"��$w"+YEL+"�Ʋ���������������𿪣���ȴ�辢���������浶��λ��ٿ����Զ��$n"+YEL+"Ѱ�ɣ�\n"+
        "����һ��������$w"+YEL+"�ػ���â�����Բ��˰����·ֱ��$n"+YEL+"���˶�������������϶��Ѱ����\n"+
        "����ɡ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ֹ�һͳ��ֻ����ս����ʹ�ã�\n");
   
    msg=HIY"$N"+HIY+"������ǰ����$w"+HIY+"��ɻ�����ߵĽ�⣬����$n"+HIY+"���ɽ���������𣬵����ٱ�������\n"+
        "���꣬��ͷ������$n"+HIY+"����ȥ��һ������ƥ�ĵ����Ծ��˵ĸ��ٺ�ջ�ȥ��������$n"+HIY+"��ȫ\n"+
        "�������֡�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ֹ�һͳ��ֻ����ս����ʹ�ã�\n");
    
    if(!me->query("perform_quest/sanfen")){
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
	   
    msg=HIG"$N"+HIG+"�ڳ����ƣ������ʶ��ư�б���ؿڣ����ֺ�$w"+HIG+"�߾ٹ�ͷ����������������ľ�����\n"+
        "����Ƶ����������$n"+HIG+"׷ȥ������ʽ��Ϊ����յأ���϶���롣\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�����ֹ�һͳ��ֻ����ս����ʹ�ã�\n");
    
    msg=MAG"$N"+MAG+"��߳һ��������������ʮ���澢���������ƣ���$n"+MAG+"�ƿ�Ϯ��������ͷ����$w"+MAG+"��\n"+
        "�����£����˹����������󺣵�ˮ������ǽ�������ֳ�ˮ�׵�ͨ��֮·��ֱȥ$n"+MAG+"��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
   
    me->set_temp("perform_busy",time());
    return 1;   
  
}
