//������
//ʨ�Ӻ�
#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	int damage,parry;
	string msg;
	
	if(target==me)
			return notify_fail("��ʨ�Ӻ�ֻ�������������ˣ�\n");
	
	if(objectp(me->query_temp("city_war_guard")))
        return notify_fail("�������������أ�\n");
	
	if(!living(target))
		return notify_fail("�ǲ��Ǹ�����Ү��\n");
	
	if(objectp(target->query_temp("city_war_guard")))
        return notify_fail("�Է������������أ�\n");
    
    if(target->is_city_war_guard()||target->query("no_roar"))
     return notify_fail("�㲻����Է�ʹ�����ֹ���\n");
        
	if(environment(me)->query("no_fight"))
	return notify_fail("���ﲻ��ʹ����ô����в�����ڹ���\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("�㲻Ҫ���ѱ����ˣ�\n");
	if(environment(me)->query("leitai"))
	return notify_fail("�����ֹʹ�����ֹ���\n");
	
	if(stringp(target->query("target_id"))
	   &&target->query("target_id")!=me->query("id"))
        return notify_fail(target->name()+"������������ս������\n");        
        if(arrayp(target->query("target_id"))
           &&member_array(me->query("id"),target->query("target_id"))==-1)
           return notify_fail(target->name()+"������������ս������\n");
        
        if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");

	if(me->query("pker"))
	return notify_fail("ͨ����������ʵ��ɣ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(!me->query_skill("wuxiang-shengong",1))
		return notify_fail("��ѧ���������ʹ�á�ʨ�Ӻ𡹣�\n");
	if((int)me->query_skill("wuxiang-shengong",1)<150)
		return notify_fail("�����������Ϊ������\n");
	if((int)me->query_skill("force",1)<150)
        return notify_fail("��Ļ����ڹ���Ϊ������\n");
	if(me->query("max_force")<1000)
		return notify_fail("���������Ϊ������\n");
	if(me->query("force")<200)
		return notify_fail("�������������ʹ�ô��ڹ���\n");
	if(time()-me->query_temp("exert_busy/roar")<10)
            return notify_fail("����ʩչ������Ҫ������������֧�֣�����Ϊ������������У�\n");
	
	me->add("force",-200);
	damage=me->query_skill("force",1);
	parry=target->query_skill("force",1);
	
          msg=HIY"$N"+HIY+"˫ĿͻȻ���������â����$n"+HIY+"����һ����š������ӷ𡱣�\n"NOR;
	   
	if(random(damage+parry)>parry){
	   damage +=me->query_skill("wuxiang-shengong",1);
	   damage=damage*4;	   
	   target->receive_damage("sen",damage);
	   msg +="\n$n����һ������Щͷ��Ŀѣ��\n\n";
            me->start_busy(1);
	}
	else
	msg +="\n$n��æ�����ڶ�����ס��$N��һ�ǡ�ʨ�Ӻ𡹣�\n\n";
            me->start_busy(1+random(2));
	message_vision(msg,me,target);
	
	if(!userp(target))
	 target->kill_ob(me);
	else
	 target->fight_ob(me);
	
	me->set_temp("exert_busy/roar",time());
	return 1;
}

