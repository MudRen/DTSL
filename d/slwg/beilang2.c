
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "北廊");
	set("long", @LONG
这里是石龙武馆的北厢廊。继续往北边走，就可以到石龙的书房和
卧室了。南边是武馆的正厅。厢廊的两旁是不大不小的荷花池，里面荷
花盛开，非常漂亮。
LONG
);


	set("exits", ([
		"northeast" :__DIR__"jiashan",
                "south":__DIR__"beilang1",
                "east":__DIR__"liaoshangshi",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
