//������
//���½��ԡ�
inherit SSERVER;

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	string msg;
	object guard;
	
	if(target!=me)
			return notify_fail("�����½��ԡ����������������ˣ�\n");
	if(environment(me)->query("no_fight"))
	return notify_fail("���ﲻ��ʹ����ô����в�����ڹ���\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("�㲻Ҫ���ѱ����ˣ�\n");
		
	if(me->query("pker"))
	return notify_fail("ͨ����������ʵ��ɣ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	
	if(!me->query_skill("yanyang-dafa",1))
		return notify_fail("��ѧ���������ʹ�á����½��ԡ���\n");
	if((int)me->query_skill("yanyang-dafa",1)<160)
		return notify_fail("�����������Ϊ������\n");
	if((int)me->query_skill("force",1)<160)
        return notify_fail("��Ļ����ڹ���Ϊ������\n");
	if(me->query("force")<300)
		return notify_fail("�������������ʹ�ô��ڹ���\n");
	if(me->query_temp("exert_yanyangdafa"))
	return notify_fail("������ʹ�������󷨡�\n");
	if(time()-me->query_temp("exert_busy/yanyangdafa")<15)
          return notify_fail("����ʩչ������Ҫ������������֧�֣�����Ϊ������������У�\n");
		
	me->add("force",-300);
	
	msg=HIR"$N"+HIR+"������������ʱ��������������������һ�㣡\n"NOR;
	message_vision(msg,me);
	me->set_temp("exert_yanyangdafa",1);
	
	guard=new(__DIR__"npc/guard");
	guard->move(environment(me));
	guard->set_leader(me);
	guard->set_status(me);
	me->add_temp_array("job_temp_killer",guard);
	target=offensive_target(me);
	if(objectp(target)){
	   if(me->is_killing(target->query("id"))){
	     guard->kill_ob(target);
	     target->kill_ob(guard);
	   }else{
	     guard->fight_ob(target);
	     target->fight_ob(guard);
	   }
	}
	
	call_out("exert2",me->query_skill("yanyang-dafa",1)/5,me,guard);
	
	return 1;
}

int exert2(object me,object guard)
{
   if(!me)
   return 1;
   if(guard)
   destruct(guard);
   
   message_vision("\n$N�ջ��������󷨡�\n\n",me);
   
   me->set_temp("exert_busy/yanyangdafa",time());
   me->delete_temp("exert_yanyangdafa");
   return 1;
}
