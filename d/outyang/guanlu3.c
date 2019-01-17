
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是一条宽敞的官路。南边就是扬州的北门了。这里的行人已经
很多了。这里渐渐热闹了起来，只见很多行人朝南边的北门涌去。
LONG);

  set("exits", ([ 
 "north":__DIR__"dalu2",
 "south":__DIR__"guanlu4",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

