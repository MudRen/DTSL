//��������
//�����ħ
//by rzy 02.9.20

#include <ansi.h>
inherit SSERVER;

void check(object me);
void remove_effect(object me);

int perform(object me,object victim)
{
        int skill;
        int base_skill,sword_skill;
        
        skill = me->query_skill("wuxiang-shengong",1);
        
        if(skill>200) skill=200;
        
        base_skill= me->query_skill("strike",1);
        sword_skill= me->query_skill("rulai-shenzhang",1);
        
        if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
                       
        if(me->query("apply_points")<=0)
        	return notify_fail("ƾ��Ŀǰ�������޷�ʩչ�������ħ����\n");
        if(me->query("max_force")<1000)
        	return notify_fail("���������Ϊ̫���ˣ�\n");              
        if(me->query_skill("wuxiang-shengong",1)<110)  
        	return notify_fail("�����������Ϊ������\n");
        if(me->query_skill("strike",1)<110)
        	return notify_fail("��Ļ����Ʒ�δ�����죡\n");
        if(me->query_skill("rulai-shenzhang",1)<110)
        	return notify_fail("����������Ʋ������죡\n");
	if(me->query_temp("actionp_hit/pomo")) {
		remove_effect(me);
		return 1;
	}
                          
        if(time()-(int)me->query_temp("perform_busy")<6)
                return notify_fail("��ո�ʩչ���������ħ������Ϣ��δƽ����\n");  
        
        message_vision(HIG"$N"+HIG+"�����������������һ�����ţ���̬��ȴ����͸��һ�����š�\n" NOR, me);
        me->set_temp("actionp_hit/pomo", 1);
        me->set_temp("pomo_time",skill/4);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
	object weapon;
	if(!me)
		return;
       
	weapon=me->query_temp("weapon");
	if(weapon) 
		remove_effect(me);
	else if(me->query_temp("pomo_time")<=0)
		remove_effect(me);                 
	else {
		me->add_temp("pomo_time",-1);
		call_out("check", 1, me);
	}
                     
}


void remove_effect(object me)
{
        if(!me) return;
        if(!me->query_temp("actionp_hit/pomo"))
        return;
        me->delete_temp("actionp_hit/pomo");
        me->set_temp("perform_busy",time());
        tell_object(me, HIG"\n�㻺�����ջ���������\n\n"NOR);
        return;
}