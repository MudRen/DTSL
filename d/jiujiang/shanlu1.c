
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。这里就是江西与岭南的交界了。南边就是岭南了。
岭南的第一大势力当属宋家堡了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tulu2",
 "southwest":__DIR__"shanlu2",
 "northwest":"/d/baling/shashilu2",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

