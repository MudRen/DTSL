//͵�콣��
//͵��
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 110 //���и�

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
	   return notify_fail("��͵�졹ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("�����޽������ʹ�á�͵�졹��\n");
    if(weapon->query("flag")==1)
		return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("toutian-jianfa",1))
    return notify_fail("��ѧ��͵�콣�������ʹ�á�͵�졹��\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("�������̫����!\n");
    if((int)me->query_skill("sword",1)<160)
    return notify_fail("��Ļ�������̫���ˣ�\n");
    if((int)me->query_skill("toutian-jianfa",1)<160)
    return notify_fail("��ġ�͵�콣�����������ң�\n");
   
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ��͵�졹��\n");
    if(me->query("perform_quest/toutian")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ��͵�졹��Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/toutian")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ��͵�졹��Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/toutian"))
    damage=damage/2;
    
    msg=HIG"$N"+HIG+"ٿ��̤ǰ���������ְ���$w"+HIG+"�������������ڣ�����ȴ��ý����������ӿ��һ����\n"+
        "���Ľ�������$n"+HIG+"�����ȥ��$N"+HIG+"�����ݱ���ޱ���ᣬ˫Ŀ��ҫ����Ȼ����ʵ�ʵ�ǿ��\n"+
        "���ţ�������������İ��ɹŰء�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��͵�졹ֻ����ս����ʹ��!\n");
    
    msg=HIY"$N"+HIY+"���һζ���$w"+HIY+"����һ�����Ī��Ĺ������ƿն�ȥ����һ����$N"+HIY+"ȫ�����ۡ�ٿ�ؽ�\n"+
        "����ѹ��бָ$n"+HIY+"���ƹ��ǹ������ط��أ��˽������֡��ۡ�����ϵ������޷죬����\n"+
        "�˸е�$N"+HIY+"�Ľ�����ȫ��ȫ�����������͸��ۡ�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��͵�졹ֻ����ս����ʹ��!\n");
        
    msg=MAG"$N"+MAG+"����ݳ�һ˿��������������Ц�ݣ����ϡ���һ�����죬���ִ����ڰγ�$w"+MAG+"����ȫ\n"+
        "û��ͣ����ԥ�����ὣ�棬�˽�һ�壬�������磬������ɵ�Զ���룬���ս��Ķ���\n"+
        "����һ���򵥵����壬����������֮�����ĸо����˽���һ�ı�ֱ��$n"+MAG+"��ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��͵�졹ֻ����ս����ʹ��!\n");
    
    if(!me->query("perform_quest/toutian")){    
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
       
    msg=HIW"$N"+HIW+"һ����Х��$w"+HIW+"��������������б�̶�����ͬʱ�����ƿ�������Ť������$w"+HIW+"�ڻ��ڱ�\n"+
        "��һ����ӳ���ܹ��߶�˸����ת�Ľ�â���ƻ�ʵ���ӭ��$n"+HIW+"�Ľ��������䡱����â\n"+
        "��ʢ��������������ʵʵ��Ӱ����ˮ��к�أ��޿ײ������$n"+HIW+"��ȥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��͵�졹ֻ����ս����ʹ��!\n");
    
    msg=HIR"$N"+HIR+"˫Ŀ��â��ʢ�����ἲ���������궯����߿���Ľ�â��ԭΪ$w"+HIR+"������ʵʵ��һ��\n"+
        "��ɨ������ƽ������������Щ��׾ζ����һ����ȴ�����й�ս������ǧ��������ɱ��\n"+
        "Ѫ���ɺӡ�ʬ��ƬҰ�������޹����ֲ��ҵĸо���\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("��͵�졹ֻ����ս����ʹ��!\n");
    
    msg=YEL"$N"+YEL+"��$w"+YEL+"����ֱ̽���ٸ߾ٹ�ͷ����һ�������Ͻ��ѣ����˫�ֳֽ�֮�ơ�����һ��ǿ\n"+
        "���������۶���ɢ�Ľ���������$w"+YEL+"����ǰ�������ı䷽����ת���Ƶ���ͷ������һ\n"+
        "��������覵���Բ�Σ��ѽ���һ����ȫ����ͷ����Ȧ���խС��Χ�ڣ�������ɢ����\n"+
        "�����ݡ������ƻ��ƿ죬�������������\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set("apply_points",0);
    me->set_temp("perform_busy",time());
    return 1;
}
