

int exert(object me, object target)
{
	int n,q;
	if (target != me) 
		return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");
	if(me->is_busy()) return notify_fail("����æ����!\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�������������\n");

if(me->query("sen")==me->query("eff_sen"))
		return notify_fail("�����ھ���ʮ�㡣\n");
	q=(int)me->query("eff_sen",1)-(int)me->query("sen",1);
	n=(int)me->query("force",1);
	if(n>=q)
	{
		me->add("force",-q);
		me->set("sen",(int)me->query("eff_sen",1));
		message_vision("$N�������˼�����,���������ö���.\n",me);
	}
	else
	{
		me->add("force",-(n-10));
		me->add("sen",n-10);
		message_vision("$N�������˼�����,�����������,����������Ҳ�ö���.\n",me);
	}
	if(me->is_fighting()) me->start_busy(1);
	return 1;
}

