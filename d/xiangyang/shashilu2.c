
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是条沙石路。这里是河南的境地。再往北走就可以到洛阳了。
往南走可以到军事重地襄阳城。
LONG);

  set("exits", ([ 
 "south":__DIR__"shashilu1",
 "north":__DIR__"shashilu3",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

