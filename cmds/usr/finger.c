// finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if( !arg ) {
		
		if( !wizardp(me) )
		 return notify_fail("��ʹ�� finger id ��\n");
		
		if( (int)me->query("sen") < 50 )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
		{
			me->receive_damage("sen", 50);
		write( FINGER_D->finger_all(0) );
		}
		else
		write( FINGER_D->finger_all(1) );

	} else {
		if( (int)me->query("sen") < 15 )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
			me->receive_damage("sen", 15);
		write( FINGER_D->finger_user(arg,wizardp(me)) );
	}
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : finger [ʹ��������]
 
���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
 
see also : who
HELP
    );
    return 1;
}
 
