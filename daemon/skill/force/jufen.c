//��ʯ���
//��ħ�󷨡�
/*
ʹ�� ��ʯ��ٺ�����������ڻ��ж��У�
��˫����ͬ����������ֻ���Լ������ˡ�
*/

#include <ansi.h>

inherit SSERVER;

int exert(object me,object target)
{ 
    object weapon;
    string msg;
    int flag,lev;
    
    flag=0;
    
   if(!me->is_fighting())
		return notify_fail("����ʯ��١�ֻ����ս����ʹ��!\n");
   if(target==me)
   return notify_fail("����ʯ��١�ֻ�ܶԱ���ʹ�á�\n");   
    if(!me->query_skill("tianmo-dafa",1))
    return notify_fail("��ѧ����ħ�󷨡����ʹ�á���ʯ��١���\n");
    
    if((int)me->query("max_force")<1000)
    return notify_fail("���������Ϊ̫���ˣ�\n");
    
       if((int)me->query("force")<300)
    return notify_fail("�����������ʹ�ô�����!\n");
    
    if(me->query_skill("tianmo-dafa",1)<400)
    return notify_fail("��ġ���ħ�󷨡���Ϊ�������޷�ʹ�����Σ�յľ�����\n");
    msg=HIC"$N"+HIC+"�ͺ�һ���������𽥷���ǿ������ħ��������$n"+HIC+"��ȥ��\n"NOR;
    
    message_vision(msg,me,target);
      
    lev=me->query_skill("tianmo-dafa",1)/2+me->query_skill("tianmo-dai",1)/2;
    
    me->add_temp("apply/dodge",lev);//��Ϊ����ƴ������Ȼ�ǵ���ɱ���֣�
    me->add_temp("apply/damage",lev);//��������Ĺ������˺������ӡ�
    
    me->add("force",-100);    
    flag=COMBAT_D->do_attack(me,target,weapon,0,1);
    me->add_temp("apply/dodge",-lev);
    me->add_temp("apply/damage",-lev);
    
    if(!me->is_fighting())
     return notify_fail("��һ���еУ����ǻ�����ȥ�������������\n");
   
   if((int)me->query("force")<100)
    return notify_fail("�����������ʹ�ô�����!\n");
    
    msg=HIY"\n$N"+YEL+"��ס�߶���ħ�󷨣����ܵ���������С��$N"+YEL+"˳�Ƴ�$n"+YEL+"����������\n"NOR;
    message_vision(msg,me,target);
    
    me->add_temp("apply/dodge",lev);
    me->add_temp("apply/damage",lev);
    
    me->add("force",-100);    
    flag +=COMBAT_D->do_attack(me,target,weapon,0,1);
    me->add_temp("apply/dodge",-lev);
    me->add_temp("apply/damage",-lev);
    
    if(!me->is_fighting())
     return notify_fail("�������еУ����ǻ�����ȥ�������������\n");
      
   if((int)me->query("force")<100)
    return notify_fail("�����������ʹ�ô�����!\n");
    
    msg=HIR"\n$N"+HIR+"���һ�߶���ħ������ֻ��һ��ǿ�����ħ������$n"+HIR+"��ȥ��$N"+HIR+"ͬʱ��������һ����\n"NOR;
    message_vision(msg,me,target);
    
    me->add_temp("apply/dodge",lev);
    me->add_temp("apply/damage",lev);
    
    me->add("force",-100);    
    flag +=COMBAT_D->do_attack(me,target,weapon,0,1);
    me->add_temp("apply/dodge",-lev);
    me->add_temp("apply/damage",-lev);
    
    if(flag>=2){//���������У�����ʯ��٣�
    
    msg=HIR"ֻ����������������������һ�㣬˲�䱬����������$N"+HIR+"��$n"+HIR+"ը����Ѫ����\n"NOR;
    msg +=RED"\nֻ��һƬѪ���ȷ糯���ܷ�ɢ������\n"NOR;
    message_vision(msg,me,target);
    
    me->remove_all_killer();
    target->remove_all_killer();
    
    me->set_temp("last_damage_msg",me->name()+"ʹ�á���ʯ��١���"+target->name()+"ͬ���ھ��ˡ�");
    target->set("last_damage_msg","��"+me->name()+"�ġ���ʯ��١�ɱ���ˡ�");
    me->delete_temp("last_damage_from");
    me->die();
    me->delete_temp("last_damage_msg");
    me->set("last_damage_msg","ʹ�á���ʯ��١���"+target->name()+"ͬ���ھ��ˡ�");
    target->die();
   
    }
    else{//���û�ɹ���
    msg=HIR"ֻ����������������������һ�㣬˲�䱬��������$n"+HIR+"ƴ������������������������˳�����\n"NOR;
    msg +=RED"\nֻ�����򡱵�һ����$N"+RED+"��ը��������Ѫ���������ܷ�ɢ������\n"NOR;
    message_vision(msg,me,target);
    me->remove_all_killer();    
    me->set_temp("last_damage_msg",me->name()+"ʹ�á���ʯ��١������ˣ�\n");
    me->delete_temp("last_damage_from");
    me->die();
    me->delete_temp("last_damage_msg");
    me->set("last_damage_msg","ʹ�á���ʯ��١������ˡ�");
    }
   
    return 1;   
  
}  
 