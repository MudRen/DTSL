
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","菜园");
  set ("long", @LONG
这里是飞马牧场的菜园。这里供应飞马牧场的粮食，只见几个人正
辛苦地在那里种地。每到秋季收获季节，这里都是一派丰收的景色。
LONG);

  set("exits", ([ 
	  "north":__DIR__"xiuxishi",
	  "east":__DIR__"caodi2",
	  "south":__DIR__"chufang",
    ]));
set("outdoors","feima");
  set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

