
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "��·");
	set("long", @LONG
���ǳɶ��������һ����·���������˼������Ľ����ˡ�ǰ��һƬ
С���֣���˵�������˽�ȥ�ܹ��ٳ�����
LONG);


	set("exits", ([
		"east" : __DIR__"daximen",
		"west":__DIR__"wroad2",
	]));
       set("outdoors", "�ɶ�");
	setup();
}



