
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","高邮湖");
  set ("long", @LONG
这里高邮湖了。湖水平静，有很多游人在这里欣赏风景。虽然是战
乱年代，但这里还是显得很平静。你不禁被这里的风景吸引住了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"caodi2",
 "south":__DIR__"caodi1",
        ]));
  set("objects",([
    __DIR__"npc/youke":2,
    ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

