//��������
//�ն�������

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage;
   
    weapon=me->query_temp("weapon");
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
    if(!me->is_fighting())
    return notify_fail("���ն�������ֻ����ս����ʹ��!\n");
    if(weapon)
    return notify_fail("�������������ʹ�á��ն���������\n");
    if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
    if(!me->query_skill("rulai-shenzhang",1))
    return notify_fail("��ѧ���������ơ����ʹ�á��ն���������\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query_skill("strike",1)<110)
    return notify_fail("��Ļ����Ʒ�̫���ˣ�\n");
    if((int)me->query_skill("rulai-shenzhang",1)<110)
    return notify_fail("��ġ��������ơ��������ң�\n");
    if((int)me->query_skill("wuxiang-shengong",1)<100)
    return notify_fail("��ġ������񹦡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ���ն���������\n");
    if(me->query("perform_quest/pudu")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("����ʩչ���ն���������Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/pudu")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ���ն���������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/pudu"))
    	damage=damage/2;
    else
    	damage += damage/4;
    
    msg=HIY"$n"+HIY+"��ǰһ����һ�Ծ���ӭ������������û���κ���ʽ���ɣ�����û�����־�����磬\n"+
        "����$N"+HIY+"�Ѵﵽ������׾������������$n"+HIY+"���������˱ܣ������Ӳ������Ƶ����֡�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ն�������ֻ����ս����ʹ��!\n");
    
    msg=YEL"$N"+YEL+"����һ�ӣ�˫�ƴ�����̽���������ץ����ʱ����һ������֮����$n"+YEL+"��������һ����\n"+
        "�������ĸо�����Ҫ����������һ�з��������ƾ������������Ӵ���ƥ��ѹ����������\n"+
        "�й���ȫ�������У�������Ҳ�类��̣�ʧȥ����������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ն�������ֻ����ս����ʹ�ã�\n");
    
    msg=MAG"$N"+MAG+"ȫ���Ʒ粻������������û������ֺ�����Ȼ���ִ��ϵǱ�Ϊƽ�죬��������һ��\n"+
        "ľ����ǰ�����ҵ�ҡ�Σ�����������ǰ�Ȼ��������𽥱仯��Ĵָ���䣬������ָ��\n"+
        "����ֱ���������ƽ��������պ�һ�ֲ���ĳ�$n"+MAG+"��$l����ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���ն�������ֻ����ս����ʹ�ã�\n");
    
    if(!me->query("perform_quest/pudu")){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    msg=HIG"$N"+HIG+"ÿ������������˹�����˿����������������$N"+HIG+"�ġ�������ȴ�պ�ʹ$n"+HIG+"���Խ��з�����\n"+
        "$n"+HIG+"���һ��������������ȷ�Ǿ������ף�\n"NOR;
    
    damage += damage/2;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
