// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 200);
        me->receive_wound("gin", 200);
        me->receive_wound("sen", 200);
	me->apply_condition("tianyi", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "���е�" HIY "��һ��ˮ" HIW "���ڷ������ˣ�\n" NOR );
	else
	tell_object(me, HIW "���е�" HIY "��һ��ˮ" HIW  "�����ˣ�\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
