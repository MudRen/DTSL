
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�������");
	set("long", @LONG
�����ϳ��ţ��������Ϸ��̵��и����ģ�κ���֡���ǽ�����ż�
�Źٸ���ʾ��һ����·����ͨ��������
LONG );
	set("exits", ([
		"south" : __DIR__"dadao9",
		"north" : __DIR__"houqiang",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	set("outdoors", "xucheng");
	setup();
	replace_program(ROOM);
}

