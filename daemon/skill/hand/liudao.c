//�ɽ�ָ
//�����ֻء�

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage,flag=0;
   
    weapon=me->query_temp("weapon");
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
   if(!me->is_fighting())
   return notify_fail("�������ֻء�ֻ����ս����ʹ��!\n");
   if(weapon)
    return notify_fail("�������������ʹ�á������ֻء���\n");
    if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
    if(!me->query_skill("dujie-zhi",1))
    return notify_fail("��ѧ���ɽ�ָ�����ʹ�á������ֻء���\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query_skill("finger",1)<110)
    return notify_fail("��Ļ���ָ��̫���ˣ�\n");
    if((int)me->query_skill("dujie-zhi",1)<110)
    return notify_fail("��ġ��ɽ�ָ���������ң�\n");
    if((int)me->query_skill("wuxiang-shengong",1)<100)
    return notify_fail("��ġ������񹦡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�������ֻء���\n");
    if(me->query("perform_quest/liudao")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("����ʩչ�������ֻء���Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/liudao")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("����ʩչ�������ֻء���Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/liudao"))
    damage=damage/2;
    me->set("apply_points",0);
    
    msg=HIY"$N"+HIY+"��ָ���ϱ仯��ʹ$n"+HIY+"�����þ����������ڡ������֮�У����ɵس��������еĻ���֮\n"+
        "�У���ȴ��Լ�о������������ĵ���֮�У�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�������ֻء�ֻ����ս����ʹ��!\n");
   /* 
    if(flag<=0){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    flag=0;
    */
    msg=HIR"$N"+HIR+"��ָ�����任��$n"+HIR+"��ǰ�����������Ȼ���밢���޵������е����ּ���֮�Ķ�ʱ���ǣ�\n"+
        "ʹ���Լ�������ģ�����壡\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�������ֻء�ֻ����ս����ʹ��!\n");
    /* 
    if(flag<=0){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    flag=0;
    */
    msg=HIC"$N"+HIC+"��ָ�����任��$n"+HIC+"��ǰ�����������Ȼ�����˵��������ϡ�����\n"+
        "����ʹ�࣬�Լ����������˱��룬����Թ���������������ۺͲ�����ȿ���һ��ӿ��\n"+
        "ͷ�������ɵ��������ᣡ\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�������ֻء�ֻ����ս����ʹ��!\n");
    
    
    if(!me->query("perform_quest/liudao")){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    call_out("perform2",3,me,target,damage);
    me->set_temp("perform_busy",time());
    return 1;   
  
}  

int perform2(object me,object target,int damage)
{
    string msg;
    int flag=0;
    
    if(!me||!target)
    return 1;
    if(!me->is_fighting(target))
    return 1;
    
    if(me->query_temp("weapon"))
    return 1;
    
    if(me->is_busy())
    return 1;
    
    msg=HIB"$N"+HIB+"��ָ�����任��$n"+HIB+"��ǰ�����������Ȼ�������������Լ���˼ά\n"+
        "��ʱģ�����������������ż��ȶ��ʵ�ʹ��ĸо���\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�������ֻء�ֻ����ս����ʹ��!\n");
    /* 
    if(flag<=0){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    flag=0;
    */
    msg=BLU"$N"+BLU+"��ָ�����任��$n"+BLU+"��ǰ�����������Ȼ������������ʱ���ú���\n"+
        "Ʈ���Ķ��������ż��ȼ��ʵĿ��գ���Զ�������޷�����ļ���������ĥ��\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("�������ֻء�ֻ����ս����ʹ��!\n");
    /* 
    if(flag<=0){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    flag=0;
    */
    msg=RED"$N"+RED+"��ָ�����任��$n"+RED+"��ǰ�����������Ȼ�������������ʱ����е�\n"+
        "��ǧ�ٸ���ǹ�������壬������ȼ�յ��Ȼ��Ѿ��޷����֣�\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    me->set_temp("perform_busy",time());
    return 1;
}
