
int exert(object me, object target)
{
	int n, q;

	if (me != target)
		return notify_fail("��ֻ�����ڹ������Լ�����Ϣ��\n");
    if(me->is_busy()) return notify_fail("����æ����!\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�������������\n");

    if(me->query("kee")==me->query("eff_kee"))
		return notify_fail("�������������档\n");
	q=(int)me->query("eff_kee",1)-(int)me->query("kee",1);
	n=(int)me->query("force",1);
	if(n>=q)
	{
		me->add("force",-q);
		me->set("kee",(int)me->query("eff_kee",1));
		message_vision("$N�������˼�����,���������ö���.\n",me);
	}
	else
	{
		me->add("force",-(n-10));
		me->add("kee",n-10);
		message_vision("$N�������˼�����,�����������,����������Ҳ�ö���.\n",me);
	}
	if(me->is_fighting()) me->start_busy(1);
	
	
	return 1;
}
