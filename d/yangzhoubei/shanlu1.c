
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路，崎岖难走，很容易迷失方向。四下一望，发现路
边有几具死尸，已经腐烂很久了。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu2",
 "southwest":__DIR__"xiaoxi1",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

