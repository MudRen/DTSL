
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是洛阳城南的郊区。从这里可以到洛阳的净念禅院。这里几乎
没有人来。
LONG);

  set("exits", ([ 
	  "east":__DIR__"xiaolu2",
	  "southwest":__DIR__"nanmen2",
  
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

