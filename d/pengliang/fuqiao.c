#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǻ�����������ǵĽ�ӣ����������Ӿ�����ǵĵؽ��ˣ�����
�����о��õĸ��ţ����Ų��Ǻܿ�����һ�������Ǻ��ʵġ�
LONG );
	set("exits", ([
		"east"     : __DIR__"heyan",
		"west"     : "/d/xucheng/dadao6",
	]));
	set("outdoors", "pingliang");
	setup();
	replace_program(ROOM);
}

