//������
//��Ϣ̥����

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	string msg;
	
	if(target!=me)
			return notify_fail("����Ϣ̥�������������������ˣ�\n");
	if(environment(me)->query("no_fight"))
	return notify_fail("���ﲻ��ʹ����ô����в�����ڹ���\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("�㲻Ҫ���ѱ����ˣ�\n");
		
	if(me->query("pker"))
	return notify_fail("ͨ����������ʵ��ɣ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(me->is_fighting())
	return notify_fail("������ս���У�\n");
	if(!me->query_skill("jiuxuan-dafa",1))
		return notify_fail("��ѧ���������ʹ�á���Ϣ̥������\n");
	if((int)me->query_skill("jiuxuan-dafa",1)<50)
		return notify_fail("��ľ�������Ϊ������\n");
	if((int)me->query_skill("force",1)<50)
        return notify_fail("��Ļ����ڹ���Ϊ������\n");
	if(me->query("force")<80)
		return notify_fail("�������������ʹ�ô��ڹ���\n");
	if(me->query_temp("exert_jiuxuandafa"))
	return notify_fail("������ʹ�þ����󷨡�\n");
	if(time()-me->query_temp("exert_busy/jiuxuandafa")<10)
          return notify_fail("����ʩչ������Ҫ������������֧�֣�����Ϊ������������У�\n");
		
	me->add("force",-80);
	
	msg=WHT"$N"+WHT+"��ϥ���£��𽥽����˯��״̬��\n"NOR;
	message_vision(msg,me);
	me->set_temp("exert_jiuxuandafa",1);
	me->set_temp("block_msg/all",1);
	me->set_temp("no_heal_up",1);
	me->set("target_id","###");
	me->set("no_get",1);
	me->set_temp("apply/short",({HIY+me->name()+HIY+"��ʩչ�Ź�Ϣ̥����\n"NOR}) );
	call_out("exert2",me->query_skill("jiuxuan-dafa",1)/3,me);
	
	return 1;
}

int exert2(object me)
{
   if(!me)
   return 1;
   
   message_vision("\n$N�ջ��˾����󷨡�\n\n",me);
   me->delete_temp("block_msg/all");
   me->delete_temp("apply/short");
   me->delete_temp("no_heal_up");
   me->delete("target_id");
   me->delete("no_get");
   tell_object(me,"���������˹�����\n");
   me->set_temp("exert_busy/jiuxuandafa",time());
   me->delete_temp("exert_jiuxuandafa");
   return 1;
}
