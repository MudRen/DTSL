// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 40);
        me->receive_wound("gin", 40);
        me->receive_wound("sen", 40);
	me->apply_condition("red_blood", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "���е�" HIR "��Ѫ��" HIW "���ڷ������ˣ�\n" NOR );
	else
	tell_object(me, HIW "���е�" HIR "��Ѫ��" HIW "�����ˣ�\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
