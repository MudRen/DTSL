
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是条宽敞大路。北边是河南最繁华的城市洛阳。这里的行人已
经很多了。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"shashilu3",
 "north":__DIR__"dalu2",
 "northwest":"/d/yinkui/xiaolu3",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

