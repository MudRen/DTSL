//������
//�����֡�
#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	string msg;
	int last_time;
	
	if(target!=me)
			return notify_fail("�������֡����������������ˣ�\n");
	if(environment(me)->query("no_fight"))
	return notify_fail("���ﲻ��ʹ����ô����в�����ڹ���\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("�㲻Ҫ���ѱ����ˣ�\n");
		
	if(me->query("pker"))
	return notify_fail("ͨ����������ʵ��ɣ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(!me->query_skill("wuxiang-shengong",1))
		return notify_fail("��ѧ���������ʹ�á������֡���\n");
	if((int)me->query_skill("wuxiang-shengong",1)<150)
		return notify_fail("�����������Ϊ������\n");
	if((int)me->query_skill("force",1)<150)
        return notify_fail("��Ļ����ڹ���Ϊ������\n");
	if(me->query("max_force")<1000)
		return notify_fail("���������Ϊ������\n");
	if(me->query("force")<200)
		return notify_fail("�������������ʹ�ô��ڹ���\n");
	if(me->query_temp("exert_jinzhong"))
	return notify_fail("������ʹ�á������֡���\n");
	if(time()-me->query_temp("exert_busy/jinzhong")<10)
          return notify_fail("����ʩչ������Ҫ������������֧�֣�����Ϊ������������У�\n");
	
	if(me->query("PKS")>=5)
        return notify_fail("���������أ��޷�ʹ�ô˾����ˣ�");
	
	me->add("force",-200);
	
	msg=HIY"$N"+HIY+"ͻȻ����һ����ţ���ʱȫ���������ģ�����������ͭǽ����һ�㣡\n"NOR;
	message_vision(msg,me);
	me->set_temp("exert_jinzhong",1);
	me->add_temp("apply/armor",me->query_skill("wuxiang-shengong",1)/2);
	
	last_time=me->query_skill("wuxiang-shengong",1)/3;
	if(last_time>=70) last_time=70;
	
	call_out("exert2",last_time,
	         me,me->query_skill("wuxiang-shengong",1)/2);
	
	return 1;
}

int exert2(object me,int armor)
{
   if(!me)
   return 1;
   
   message_vision("\n$N�ջ��������񹦡�\n\n",me);
   me->add_temp("apply/armor",-armor);
   me->set_temp("exert_busy/jinzhong",time());
   me->delete_temp("exert_jinzhong");
   return 1;
}
