//�������ƾ���
#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	int last_time;
	
	if(target!=me)
			return notify_fail("��ֻ�ܶ��Լ�ʹ�����ģ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
        if((int)me->query_skill("qingxin-force",1)<120)
		return notify_fail("����������ƾ���Ϊ������\n");
	if((int)me->query_skill("force",1)<100)
		return notify_fail("��Ļ����ڹ���Ϊ������\n");
        if(me->query("force")<200)
		return notify_fail("�������������ʹ�ô��ڹ���\n");
	if(me->query_temp("execute_qingxinforce"))
	return notify_fail("������ʹ���������ƾ���\n");
	if(time()-me->query_temp("execute_qingxinforce_busy")<10)
          return notify_fail("����ʩչ������Ҫ������������֧�֣�����Ϊ������������У�\n");
	message_vision(MAG"$N"+MAG+"������һ���������ж�ʱ�������쳣��\n"NOR,me);
	me->add_temp("apply/dodge",me->query_skill("qingxin-force",1)/7);
  me->add("force",-200);
	me->set_temp("execute_qingxinforce",1);
	
	last_time=me->query_skill("qingxin-force",1)/3;
	if(last_time>=70) last_time=70;
	
  call_out("cancel_exert",last_time,me,
        me->query_skill("qingxin-force",1)/7);
	return 1;
}

int cancel_exert(object me,int i)
{
  if(!objectp(me))
  return 1;
  me->add_temp("apply/dodge",-i);
  message_vision(HIY"$N"+HIY+"������һ��������ɫ�ָ�ƽ����\n"NOR,me);
  me->delete_temp("execute_qingxinforce");
  me->set_temp("execute_qingxinforce_busy",time());
  return 1;
}
