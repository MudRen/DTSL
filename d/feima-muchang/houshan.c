
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","后山");
  set ("long", @LONG
这里飞马牧场的后山。这里几乎没有人，冷冷清清的。有很多人牵
着马朝远处走去。远处可以看到几个牧场，有几个飞马牧场的弟子正在
那里放牧养马。
LONG);

  set("exits", ([ 
	  "northeast":__DIR__"xiaolu4",
    ]));
 
  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

