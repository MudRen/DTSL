
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��Ǳ���");
	set("long", @LONG
���Ǳ����ţ��������Ϸ��̵��и����ġ�κ���֡���ǽ�����ż�
�Źٸ���ʾ��һ����·����ͨ��ɽ����
LONG );
	set("exits", ([
		"north" : __DIR__"dadao10",
		"south" : __DIR__"beidajie",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}

