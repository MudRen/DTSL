
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","花园");
  set ("long", @LONG
这里是一花园，这里种了很多花。这里是飞马牧场英雄们练习武艺
和休息的地方。北边是一个练武场，南边是一个厨房。不时有飞马牧场
弟子从这里走过。
LONG);

  set("exits", ([ 
 "out":__DIR__"wanxiaotang",
 "north":__DIR__"lianwuchang",
 "southdown":__DIR__"chufang",
 "eastdown":__DIR__"zhulin",
      ]));
  set("valid_startroom", 1);
  set("outdoors","feima");
  setup();
 
}
