// night.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int night_value;
	object obj;

	if( !arg||(arg!="1"&&arg!="0") ) 
		return notify_fail("���󣡲���Ӧ����1��0\n");
	if(arg=="1")
		night_value=1;
	if(arg=="0")
		night_value=0;
	NATURE_D->set_night(night_value);
	return 1;
}

