//��ӰѰ��
//by rzy 2002.11.11

#include <ansi.h>

inherit SSERVER;


int perform(object me,object target)
{
    object weapon;
    string msg;
    int flag=0,damage;

    if(!target)
    if(!objectp(target=offensive_target(me)))
        return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
    if(!me->is_fighting())
        return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
        return notify_fail("�����޽������ʹ�á���ӰѰ������\n");
    if(weapon->query("flag")==1)
        return notify_fail("�ϵ��ı������ʹ�ã�\n");
    if(!me->query_skill("yingzi-jianfa",1))
        return notify_fail("��ѧ��Ӱ�ӽ��������ʹ�á���ӰѰ������\n");
    if((int)me->query("max_force",1)<3000)
        return notify_fail("�������̫����!\n");
    if((int)me->query("PKS")<1)
        return notify_fail("��û�б����������޷�ʹ����˺�����������\n");
    if((int)me->query_skill("sword",1)<220)
        return notify_fail("��Ļ�������̫���ˣ�\n");
    //if((int)me->query("bellicosity")<5000)
    //    return notify_fail("���ɱ��̫�ᣬ�޷�ʹ����˺�����������\n");
    //����ʱ���ֺ�������ɱ��������,�����Ȳ�������������ˡ�
    if((int)me->query_skill("yingzi-jianfa",1)<220)
        return notify_fail("��ġ�Ӱ�ӽ������������ң�\n");
    if((int)me->query_skill("dodge",1)<220)
        return notify_fail("��ġ������Ṧ���������ң�\n");
    if((int)me->query("kee")>(me->query("max_kee")*99/100))
        return notify_fail("��û�����ˣ��޷�ʩչ����ӰѰ������\n");
    if(me->query("apply_points")<me->query("max_apply_points")/2)
        return notify_fail("ƾ��Ŀǰ�������޷�ʩչ����ӰѰ������\n");

    if(me->query("vocation")!="ɱ��")
    return notify_fail("ֻ��ɱ�ֲ���ʩչ����ӰѰ������\n");

     if(me->query("job_office_number/ɱ������")>=500 && me->query("vocation_score")>100)
    flag=1;
    
    if(flag
      &&time()-me->query_temp("perform_busy")<16)
       return notify_fail("����ʩչ����ӰѰ������Ҫ������������֧�֣�����Ϊ������������У�\n");
    if(!flag
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("����ʩչ����ӰѰ������Ҫ������������֧�֣�����Ϊ������������У�\n");

    if(flag)
    damage=me->query("apply_points")+(me->query("max_kee")-me->query("kee"))/10;
    else
    damage=(me->query("max_kee")-me->query("kee"))/10;

    msg=BLU"$N"+BLU+"����Ǳ�������μӿ죬��������Ӱ�ӴӸ���������$n"+BLU+"Ҫ����\n˲��������������"+
        "����������������\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");

    if(!me->is_fighting())
    return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");

    if(me->query("kee")>me->query("max_kee")*95/100){
    me->set_temp("perform_busy",time()-2);
    return notify_fail("��Ŀǰ������ֻ�ܼ������Ǳ�ܷ�һ�У�\n");
    }

    msg=BLU"������$N"+BLU+"���ٴμӿ죬һʱ��ǰ�����Ҿ���$N"+BLU+"����Ӱ�����콣Ӱ�в�������\n�����Ľ���ʹ$n"+BLU+"����"+
        "ֹͣ��ȫ�����������Ѱ�ʹ����\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");

    if(!me->is_fighting())
    return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");

    if(me->query("kee")>me->query("max_kee")*80/100){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("��Ŀǰ������ֻ�ܼ������Ǳ�ܷ����У�\n");
    }
    msg=BLU"$n"+BLU+"ֻ��ѹ���������󣬺�Х�ľ���������������գ�$N"+BLU+"������������޷���׽λ�ã�\n$n"+BLU+"��Ŀ��"+
        "ä����ƾ��Ӱ�Ӹ����������������мܶ�ܶ��޴����֣�\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");

    if(!me->is_fighting())
    return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");

    if(me->query("kee")>me->query("max_kee")*65/100){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("��Ŀǰ������ֻ�ܼ������Ǳ�ܷ����У�\n");
    }
    msg=HIB"$N"+HIB+"���Ʒ������������Ǳ��������ͻ�������磬�ڸ��ٶ����������ʵ��\n��Ľ�������խ�ռ��ٴα���"+
        "�ޱߵ�ս������$n"+HIB+"�ĵ��㺮���޷����������������\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");

    if(!me->is_fighting())
    return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");

    if(me->query("kee")>me->query("max_kee")*45/100){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("��Ŀǰ������ֻ�ܼ������Ǳ�ܷ����У�\n");
    }
    else if(me->query_skill("yingzi-jianfa",1)<300) {
        me->set_temp("perform_busy",time()-2);
        return notify_fail("��Ľ�����Ϊֻ�ܷ������У�\n");
    }
    
    if(flag) {
	    message_vision(HIG"\n$N"+HIG+"��ʽ���䣬һ��Ӱ�ӽ�����ĥ�����·���ȵ�·���������˱������ٴ���������Ǳ����\n"+
	                      "��ȫ��������ע��������һ��������"+weapon->query("name")+HIG+"��Ϊ������������$n"+HIG+"��\n"+
	                      "������ǰ����Ľ���������һ�㣡\n"NOR,me,target);
            me->add_temp("apply/damage",damage);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            me->add_temp("apply/damage",-damage);
            
            if(!me->is_fighting())
            return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");
    
            if(me->query("kee")>me->query("max_kee")*15/100){
            me->set_temp("perform_busy",time()-2);
            return notify_fail("��Ŀǰ������ֻ�ܼ������Ǳ�ܳ����У�\n");
            }

    }
    if(!flag) {
    
            msg=HIG"\n$N"+HIG+"��ʽ���䣬һ��Ӱ�ӽ�����ĥ�����·���ȵ�·���������˱������ٴ���������Ǳ����\n"+
                   "��ȫ��������ע��������"+weapon->query("name")+HIG+"��Ϊ���繥��$n"+HIG+"�����������֮����\n"NOR;
            me->set_temp("action_msg",msg);
            me->add_temp("apply/damage",damage);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            me->add_temp("apply/damage",-damage);
            me->delete_temp("action_msg");
            
            if(!me->is_fighting())
            return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");
    
            if(me->query("kee")>me->query("max_kee")*15/100){
            me->set_temp("perform_busy",time()-2);
            return notify_fail("��Ŀǰ������ֻ�ܼ������Ǳ�ܳ����У�\n");
            }
    
    }

    if(flag) {
    	if(random(100)==1) {
            damage=damage*10;
            msg=RED"$N"+RED+"����֮������һƬ������������Ȼ���������߾��磬����"+weapon->query("name")+RED+"����ϸ΢���޷�����Ķ�����\n"+
                   "$N"+RED+"̧������һ�Ž��⣬��â����$N"+RED+"����һ����Ӱ��ȴ������������"+weapon->query("name")+RED+"����˻���Ϊ\n"+
                   "Ӱ��������ʹ���Ҳ���Ѷ�ܣ�\n"NOR;
                me->set_temp("action_msg",msg);
                me->add_temp("apply/damage",damage);
                COMBAT_D->do_attack(me,target,weapon,0,2);
                me->add_temp("apply/damage",-damage);
                me->delete_temp("action_msg");
                
                if(!me->is_fighting())
       		return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n"); 
        }
        else {
    	    message_vision(RED"\n$N"+RED+"����֮������һƬ������������Ȼ���������߾��磬����"+weapon->query("name")+RED+"����ϸ΢���޷�����Ķ�����\n"+
    	                      "$N"+RED+"̧������һ�Ž��⣬��â���������ν������������"+weapon->query("name")+RED+"����������������һ�ж�������\n"+
    	                      "��ɣ���и�ɻ���\n"NOR,me,target);
            me->add_temp("apply/damage",damage);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            COMBAT_D->do_attack(me,target,weapon,0,2);
            me->add_temp("apply/damage",-damage);
            
            if(!me->is_fighting())
	    return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n"); 
        }
     }
       
     if(!flag) {   
     	
            msg=RED"$N"+RED+"����֮������һƬ������������Ȼ���������߾��磬����"+weapon->query("name")+RED+"����ϸ΢���޷�����Ķ�����\n"+
                   "$N"+RED+"̧������һ�Ž��⣬��â��$N"+RED+"�˽���һ������������ĸ��ٶȹ���$n"+RED+"��\n"NOR;
                me->set_temp("action_msg",msg);
                me->add_temp("apply/damage",damage);
                COMBAT_D->do_attack(me,target,weapon,0,2);
                me->add_temp("apply/damage",-damage);
                me->delete_temp("action_msg");
       
       		if(!me->is_fighting())
       		return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");    	
       
       }
    
    if(!me->is_fighting())
       return notify_fail("����ӰѰ����ֻ����ս����ʹ��!\n");    

    me->set_temp("perform_busy",time());
    return 1;

}
