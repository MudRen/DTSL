#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���ǺӱߵĿ鿪���ء����ϼ��ż������ţ�����һ�������������
��֪��ͨ�����
LONG );
	set("exits", ([
		"eastup"     : __DIR__"shanlu3",
		"west"     : __DIR__"fuqiao",
	]));
	set("outdoors", "pingliang");
	setup();
	replace_program(ROOM);
}

