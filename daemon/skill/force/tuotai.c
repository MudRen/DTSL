//���մ󷨡���̥���ǡ�

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	if(target!=me)
			return notify_fail("��ֻ�ܶ��Լ�ʹ����̥���ǣ�\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
        if((int)me->query_skill("huanri-dafa",1)<120)
		return notify_fail("��Ļ��մ���Ϊ������\n");
        if((int)me->query_skill("force",1)<120)
        return notify_fail("��Ļ����ڹ���Ϊ������\n");
	if(me->query("max_force")<2000)
		return notify_fail("���������Ϊ������\n");
        if(me->query("force")<200)
		return notify_fail("�������������ʹ�ô��ڹ���\n");
	
	if(me->query_temp("exert_huanri"))
	return notify_fail("������ʹ�ô��ڹ���\n");
	
	if(time()-me->query_temp("exert_huanri_busy")<10)
          return notify_fail("����ʩչ����̥���ǡ���Ҫ������������֧�֣�����Ϊ������������У�\n");
	
	message_vision(HIR"$N"+HIR+"������һ����������ͻȻ������֣�ȫ��������죡\n"NOR,me);
	
	me->add_temp("apply/damage",me->query_skill("huanri-dafa",1));
	me->add_temp("apply/dodge",me->query_skill("huanri-dafa",1));
	me->add_temp("apply/armor",me->query_skill("huanri-dafa",1));
	
        me->add("force",-200);
	me->set_temp("exert_huanri",1);
        call_out("cancel_exert",me->query_skill("huanri-dafa",1)/6,me);
	return 1;
}

int cancel_exert(object me)
{
  if(!objectp(me))
  return 1;
  
  me->add_temp("apply/damage",-me->query_skill("huanri-dafa",1));
  me->add_temp("apply/dodge",-me->query_skill("huanri-dafa",1));
  me->add_temp("apply/armor",-me->query_skill("huanri-dafa",1));
  
  message_vision(HIY"$N"+HIY+"������һ���������ϵĺ����������ȥ��\n"NOR,me);
  me->delete_temp("exert_huanri",1);
  me->set_temp("exert_huanri_busy",time());
  return 1;
}
