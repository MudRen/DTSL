
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是一条沙石路。由于近来兵荒马乱，所以行人很少，显得很凄
凉。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shashilu1",
  "southwest":__DIR__"guanlu3",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

