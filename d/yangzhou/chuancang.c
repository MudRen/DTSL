
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","前船舱");
  set ("long", @long
这里比现象中要宽阔的多，足够一队舞女表演乐舞，以及坐下十几
个客人，旁边有楼梯可以到楼上单间坐坐，呆在这里根本听不见外界发
生的事情，美酒，舞女，可以说是人间仙境。
long);

  set("exits", ([ 
 "south":__DIR__"huafang",
 "up":__DIR__"2chuancang1",
 "north":__DIR__"chuancang1",
 
        ]));
 set("objects",([
	 __DIR__"npc/wunv":4,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

