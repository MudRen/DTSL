
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "化装室");
	set("long", @long
这里是船上的化装室，几个舞女在补妆。	
long);
	set("exits", ([
		"west" :__DIR__"chuancang2",
	]));
	set("objects",([
	    __DIR__"npc/wunv":2,
	    ]));
	set("valid_startroom", 1);
	setup();
}
