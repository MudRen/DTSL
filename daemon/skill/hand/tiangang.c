//���ȭ
//�������

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
    return notify_fail("���������ֻ����ս����ʹ��!\n");
    if(weapon)
    return notify_fail("�������������ʹ�á����������\n");
    if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
    if(!me->query_skill("tiangang-quan",1))
    return notify_fail("��ѧ�����ȭ�����ʹ�á����������\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("���������Ϊ̫����!\n");
    if((int)me->query_skill("cuff",1)<110)
    return notify_fail("��Ļ���ȭ��̫���ˣ�\n");
    if((int)me->query_skill("tiangang-quan",1)<110)
    return notify_fail("��ġ����ȭ���������ң�\n");
    if((int)me->query_skill("wuxiang-shengong",1)<100)
    return notify_fail("��ġ������񹦡��������ң�\n");
    if(me->query("apply_points")<=0)
    return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�����������\n");
    if(me->query("perform_quest/tiangang")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ�����������Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!me->query("perform_quest/tiangang")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("����ʩչ�����������Ҫ������������֧�֣�����Ϊ������������У�\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/tiangang"))
    damage=damage/2;
    
    msg=MAG"$N"+MAG+"�ʹ���������������¶��һ�������Ѳ⣬��������ʥ���ǻ۵���⣬������ɫ��ɮ\n"+
        "�����°��ݣ�����ȫ��һȭ����������������ˮ����������ҽǣ�����������\n"NOR;
    
    flag=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���������ֻ����ս����ʹ��!\n");
    
    msg=MAG"$N"+MAG+"˫ȭ�㼯��ȫ�����������ʱȫ���������ͣ�˫Ŀ�ų����˵Ĺ�â����$n"+MAG+"�Ծ�֮�ʣ�\n"+
        "$N"+MAG+"��˫ȭ�������������ӳ���ֻ��һ��ǿ���������$n"+MAG+"��ȥ��"NOR;
    
    flag +=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("���������ֻ����ս����ʹ�ã�\n");
    
    if(!me->query("perform_quest/tiangang")){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    if(flag>0){
      msg="\n\n$N��$n������ײ����һ��ֻ�����顱��һ��������������������\n"+
          "���˾�����ɫ�԰ף�����ҡ�Σ�\n\n";
      message_vision(msg,me,target);
      me->set("force",0);
      target->set("force",0);
    }    
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
