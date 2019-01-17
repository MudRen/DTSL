#include <ansi.h>
inherit SSERVER;

void check(object me);
void remove_effect(object me);

int perform(object me,object victim)
{
        int skill;
        int base_skill,sword_skill;
        
        skill = me->query_skill("tiangang-sanjue",1);
        
        if(skill>200) skill=200;
        
        base_skill= me->query_skill("sword",1);
        sword_skill= me->query_skill("dijian-jue",1);
                       
        if(me->query("apply_points")<=0)
        return notify_fail("ƾ��Ŀǰ�������޷�ʩչ������������!\n");
        if(me->query("max_force")<1000)
        return notify_fail("���������Ϊ̫���ˣ�\n");              
        if( skill < 110 )  return notify_fail("������������Ϊ������\n");
        if( base_skill < 110 )  return notify_fail("��Ļ�������δ�����졣\n");
        if( sword_skill < 110 )  return notify_fail("��ĵؽ���δ�����졣\n");
                
        if( me->query_temp("actionp_hit/feilong") ) 
          {remove_effect(me);return 1;}
                          
        if( time()-(int)me->query_temp("perform_busy") < 6 )
                return notify_fail("����������������\n");  
        
        message_vision(HIY"$N"+HIY+"�ӿ����Σ�ʩչ������������\n" NOR, me);
        me->set_temp("actionp_hit/feilong", 1);
        me->set_temp("feilong_time",skill/3);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
        object weapon;
         if(!me)//���û����� me������me quit�ˣ��򷵻أ������κ���
        return;
       
        weapon=me->query_temp("weapon");
        if ( !weapon||weapon->query("skill_type") != "sword" ) 
                 remove_effect(me);
         else if(me->query_temp("feilong_time")<10)
             remove_effect(me);                 
         else {  me->add_temp("feilong_time",-1);
                call_out("check", 1, me);
              }
                     
}


void remove_effect(object me)
{
        if(!me) return;//���û����� me������me quit�ˣ��򷵻أ������κ���
        if(!me->query_temp("actionp_hit/feilong"))
        return;
        me->delete_temp("actionp_hit/feilong");
        me->set_temp("perform_busy",time());
        tell_object(me, HIG"\n���ջ��˵ؽ�����\n\n"NOR);
        return;
}
