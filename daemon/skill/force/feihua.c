//�ɻ���ˮ��
//�ɻ���

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	string msg;
	int ap,vp;
	
	if(target==me)
			return notify_fail("���ɻ���ֻ�������������ˣ�\n");
	if(!me->is_fighting(target))
	 return notify_fail("�ⲻ����ս����Ŀ�꣡\n");
	if(environment(me)->query("no_fight"))
	return notify_fail("���ﲻ��ʹ����ô����в�����ڹ���\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("�㲻Ҫ���ѱ����ˣ�\n");
		
	if(me->query("pker"))
	return notify_fail("ͨ����������ʵ��ɣ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(!me->query_skill("flower-force",1))
		return notify_fail("��ѧ�ɻ���ˮ���ʹ�á��ɻ�����\n");
	if((int)me->query_skill("flower-force",1)<150)
		return notify_fail("��ķɻ���ˮ��Ϊ������\n");
	if((int)me->query_skill("force",1)<150)
        return notify_fail("��Ļ����ڹ���Ϊ������\n");
	if(me->query("max_force")<1000)
		return notify_fail("���������Ϊ������\n");
	if(me->query("force")<200)
		return notify_fail("�������������ʹ�ô��ڹ���\n");
	if(me->query_temp("exert_feihualiushui"))
	return notify_fail("������ʹ�÷ɻ���ˮ��\n");
	if(time()-me->query_temp("exert_busy/feihualiushui")<5)
          return notify_fail("����ʩչ������Ҫ������������֧�֣�����Ϊ������������У�\n");
		
	me->add("force",-200);
	
	msg=HIG"$N"+HIG+"���ٻζ���˲�����˼�����Ӱ��\n"NOR;
	
	ap=me->query_skill("flower-force",1);
	vp=target->query_skill("force",1);
	
	if(random(ap+vp)>vp){
	   msg+="\n$n����ͷ����Щ���Σ�������Щ�ٻ��ˣ�\n\n";
	   target->start_busy(3);
	}
	else{
	   msg+="\n$n�������񣬾����ȴ���$N�ĳ��֡�\n\n";
	}
	
	message_vision(msg,me,target);
	
	me->set_temp("exert_busy/feihualiushui",time());
	
	return 1;
}

