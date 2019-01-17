
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里条小路。北边有一片草地。一阵风吹来，带来阵阵水的气息，
看来附近必定有湖水或河流了。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"caodi1",
 "southwest":__DIR__"xiaolu1",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

