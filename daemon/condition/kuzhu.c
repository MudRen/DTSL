// TIE@FY3
#include <ansi.h>
int update_condition(object me, int duration)
{
	me->receive_heal("sen", 15);
	message_vision("$N������һ�ݣ������ƺ��ֺ���һЩ��\n",me);
	me->apply_condition("kuzhu", duration - 1);
	if( duration < 1 ) 
		return 0;
	return 1;
}
