//ʨ��ӡ
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int flag,damage;
     string msg;
     object weapon;
     weapon=me->query_temp("weapon");
     
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
    if(weapon)
    return notify_fail("�������������ʹ�á�ʨ��ӡ����\n");
    if(!me->is_fighting())
    return notify_fail("ֻ����ս��ʱ�ſ���ʹ�á�ʨ��ӡ����\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("��ѧ���������ԡ����ʹ�á�ʨ��ӡ����\n");
    if((int)me->query("max_force")<3000)
    return notify_fail("���������Ϊ̫����!\n");   
    if((int)me->query_skill("jiuzi-zhenyan",1)<160)
    return notify_fail("��ľ�������̫���ˣ�\n");
    if((int)me->query_skill("strike",1)<160)
    return notify_fail("��Ļ����Ʒ��������ң�\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ��ʨ��ӡ����\n");
    
    if(me->query_skill("jiuzi-zhenyan",1)>=180)
     flag=1;
    else
     flag=0;
    
        if(flag&&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ��ʨ��ӡ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    if(flag&&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ��ʨ��ӡ����Ҫ������������֧�֣�����Ϊ������������У�\n");
    damage=me->query("apply_points");
    if(flag) damage=damage*3/2;
    else damage=damage/2;
    
    msg=HIY"$N"+HIY+"һ�����壬��Цһ����ٿ��������ȥ��ͬʱ��������ת�ɣ�ɨ��$n"+HIY+"�����̣�����\n"+
        "����$n"+HIY+"��$l��ͬʱ���ְ���ʨ��ӡ������һ�����͡���\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    if(!me->is_fighting())
    return notify_fail("��ʨ��ӡ��ֻ����ս����ʹ��!\n");
    
    msg=HIC"$N"+HIC+"�����Թ�����룬��ʱ������ȫ���Ĳ���ɭɱ֮����ȥ����������ҹ��ʱ����Ժ��\n"+
        "��������������ƺ�Զ����ߣ��������ڶ��ԣ��о��������ף��������ĺ����ƣ���\n"+
        "�������㡣\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    if(!me->is_fighting())
    return notify_fail("��ʨ��ӡ��ֻ����ս����ʹ��!\n");
    
    msg=WHT"ֻ��$N"+WHT+"���ݲ��������������Ĳ����������뾲�ĸ�ɮ������ׯ�ϣ�������һ��˵��\n"+
        "���ķ����������϶��γ����ص������������������ĵ����ȣ���$n"+WHT+"��������о���\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    if(!me->is_fighting())
    return notify_fail("��ʨ��ӡ��ֻ����ս����ʹ��!\n");
    
    msg=HIG"$N"+HIG+"΢΢һЦ����Ȼһȭ��������ȭ�����������������ĸо�����ʵ�ϼȴ�������ȭ\n"+
        "�磬��û��˿����������$n"+HIG+"�ɻ�ʱ��ٿ�ء����һ���������ڰ�յ�ȭͷ�������\n"+
        "��ƥ�ľ��������$n"+HIG+"ֱ����ȥ��\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    me->set_temp("perform_busy",time());
    
    return 1;   
  
}  
