
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"����ӵļ�"NOR);
        set("long", "test room"

);
       
        set("exits",([
			"northwest" : __DIR__"test",
			"north" : __DIR__"test",
			"northeast" : __DIR__"test",
			"west" : __DIR__"test",
			"east" : __DIR__"test",
			"southwest" : __DIR__"test",
			"south" : __DIR__"test",
			"southeast" : __DIR__"test",
        ]));
      
        setup();
}

