
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","花园");
  set ("long", @LONG
这里是个花园。这里种了很多名贵的花草，一阵风吹来，香气扑鼻。
群花争奇斗艳，竟相开放。有几个花匠正在这里修剪着花草。南边是一片
草地。
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaojing2",
 "south":__DIR__"caodi2",
     ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

