

int exert(object me, object target)
{
		int n,q;
	if (target != me) 
		return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�Ѫ��\n");
	if(me->is_busy()) return notify_fail("����æ����!\n");
	if ((int)me->query("force") < 20)
		return notify_fail("�������������\n");

        if(me->query("gin")>=me->query("eff_gin"))
		return notify_fail("�����ھ������档\n");
	q=(int)me->query("eff_gin",1)-(int)me->query("gin",1);
	n=50*q/me->query_skill("force",1);
	if (n < 20)
		n = 20;
	if ((int)me->query("force") < n) {
		q = q * (int)me->query("force") / n;
		n = (int)me->query("force");
	}
	me->add("force", -n);
	me->receive_heal("gin", q);
	
        message_vision("$N�������˼����������������ö��ˡ�\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	return 1;
}

