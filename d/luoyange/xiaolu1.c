
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是条小路。这里的人已经不是很多了。南面就是洛河了。这里
风景秀丽，山水如画，空气清新。地上有很多漂亮的野花、蒲公英等植
物。不时有野兔从你的脚旁跳过。
LONG);

  set("exits", ([ 
  "west":__DIR__"guanlu2",
  "east":__DIR__"xiaolu2",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

