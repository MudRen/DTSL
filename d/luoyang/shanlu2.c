
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是秦岭上的一条山路。这里的树木郁郁葱葱，风景非常美丽。
不过没有人敢在这里停留，据说这里会有强盗出没。
LONG);

  set("exits", ([ 
  "northdown":__DIR__"shanlu1",
  "westup":__DIR__"shanlu3",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

