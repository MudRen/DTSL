#include <room.h>

inherit ROOM;
void create()
{
	set("short", "Ӫ��");
	set("long", @LONG
����������Ӫ��Ӫ����һ����ľ��ɷ������, �ſڿյ�����ʿ��
Χ�ɸ�Ȧ�����֣����ľ��г����������������Ӣ�ۣ�ʿ���������Ǳ�
�δ󺺡�
LONG );
	set("exits", ([
		"south" : __DIR__"junying",
	]));
	set("objects", ([
		__DIR__"npc/bing" :3,
	]));
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}

