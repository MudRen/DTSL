#include <ansi.h>
inherit SSERVER;

void check(object me);
void remove_effect(object me);

int perform(object me,object victim)
{
        int skill;
        int sword_skill,qixiu_skill;
        
        skill = me->query_skill("tianmo-dafa",1);
        if( skill > 250 ) skill=250;
        sword_skill= me->query_skill("dagger",1);
        qixiu_skill= me->query_skill("tianmo-zhan",1);
                       
        if(me->query("apply_points")<=0)
        return notify_fail("ƾ��Ŀǰ�������޷�ʩչ����ħ����ն��!\n");
        if(me->query("max_force")<1500)
        return notify_fail("���������Ϊ̫���ˣ�\n");              
        if( skill < 160 )  return notify_fail("�����ħ����Ϊ������\n");
        if( sword_skill < 160 )  return notify_fail("��Ļ���ذ��δ�����졣\n");
        if( qixiu_skill < 160 )  return notify_fail("�����ħնδ�����졣\n");
                
        if( me->query_temp("actionp_hit/lingxiao") ) 
          {remove_effect(me);return 1;}
                          
        if( time()-(int)me->query_temp("perform_busy") < 10 )
                return notify_fail("����������������\n");  
        
        me->add("force", -skill);
        message_vision(HIR "$N"+HIR+"�߶���ħ�󷨣����ͼ�ת���㲻մ�أ�������Ȱ�Ʈ��������\n" NOR, me);
        me->set_temp("actionp_hit/lingxiao", 1);
        me->set_temp("lingxiao_time",skill/5);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
        object weapon;
         if(!me)//���û����� me������me quit�ˣ��򷵻أ������κ���
        return;
       
        weapon=me->query_temp("weapon");
        if ( !weapon||weapon->query("skill_type") != "dagger" ) 
                 remove_effect(me);
         else if(me->query_temp("lingxiao_time")<1)
             remove_effect(me);                 
         else {  me->add_temp("lingxiao_time",-1);
                call_out("check", 1, me);
              }
                     
}


void remove_effect(object me)
{
        if(!me) return;//���û����� me������me quit�ˣ��򷵻أ������κ���
        if(!me->query_temp("actionp_hit/lingxiao"))
        return;
        me->delete_temp("actionp_hit/lingxiao");
        me->set_temp("perform_busy",time());
        tell_object(me, HIG"\n�㽫��ħ���ջص��\n\n"NOR);
        return;
}
