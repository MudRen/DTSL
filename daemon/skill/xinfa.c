//�ķ�.

#include <ansi.h>
inherit SKILL;

string execute_action_file(string action)
{
	return __DIR__"exec/"+action;
}