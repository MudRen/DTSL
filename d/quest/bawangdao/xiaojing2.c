
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "小径");
	set("long", @LONG
这是一条小径，曲曲折折，不知道能通向什么地方。这里有些阴凉。
你不禁小心起来。
LONG
	);


	set("exits", ([
		"south" :__DIR__"xiaojing",
		"west":__DIR__"fendi",
	]));
       set("outdoors", "成都");
	setup();
}

