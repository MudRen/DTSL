//������
//ȺХ��


#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int perform(object me,object target)
{
       object *t;
       int i,fight_flag=0,damage;
  		
	if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("Ŀǰ��û�й�����Ŀ�꣡\n");
	
	if(!me->is_team_leader())
	return notify_fail("�㲻�Ƕ�������죬�޷�ʩչ��ȺХ����\n");
	
	if(!me->is_fighting())
	return notify_fail("��ȺХ��ֻ����ս����ʹ�ã�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(!me->query_skill("youlong-shenfa",1))
		return notify_fail("��ѧ���������ʹ�á�ȺХ����\n");
	if((int)me->query_skill("youlong-shenfa",1)<100)
		return notify_fail("�����������Ϊ������\n");
	if((int)me->query_skill("dodge",1)<100)
		return notify_fail("��Ļ����Ṧ��Ϊ������\n");
	if(me->query("apply_points")<=0)
	return notify_fail("������Ʋ�����ʹ�á�ȺХ����\n");
	
	if(time()-me->query_temp("form_busy")<15)
      return notify_fail("����ʩչ��ȺХ����Ҫ������������֧�֣�����Ϊ������������У�\n");
        
        t=me->query_team();
        t=t-({0});
        if(sizeof(t)<2) return notify_fail("Ҫʩչ��ȺХ���������������ˣ�\n");
        
        for(i=0;i<sizeof(t);i++)
         if(objectp(t[i])){
         if(environment(t[i])!=environment(me))
         return notify_fail("���˲�����վ��һ��\n");
         if(t[i]->query_skill("youlong-shenfa",1)<100)
         return notify_fail(t[i]->name()+"��������Ϊ̫���ˣ�\n");
       }
       
       if(me->is_killing(target->query("id")))
       fight_flag=1;
       message_vision(HIR"\n$N"+HIR+"һ����Х�������󡹣�����Х���������˵�����\n"NOR,me);
       
       for(i=0;i<sizeof(t);i++){
         if(!t[i]->is_fighting(target)){
           if(fight_flag) {t[i]->kill_ob(target);target->kill_ob(t[i]);}
           else {t[i]->fight_ob(target);target->fight_ob(t[i]);}
         }
        t[i]->set_temp("form_busy",time());
        damage=t[i]->query("apply_points");
        t[i]->add_temp("apply/damage",damage);
        COMBAT_D->do_attack(t[i],target,t[i]->query_temp("weapon"),0,2);
        t[i]->add_temp("apply/damage",-damage);
      }
        me->set_temp("form_busy",time());
        return 1;
}

