// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 7);
	me->receive_damage("sen", 10);
	me->apply_condition("no_shadow", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "���е�" HIC "��Ӱ��" HIW "��������ˣ�\n" NOR );
	else
	tell_object(me, HIW "���е�" HIC "��Ӱ��" HIW "�����ˣ�\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
