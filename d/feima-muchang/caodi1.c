
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片青草地。南边是一个小花园。有很多人牵着马朝外走去。
远处可以看到几个牧场，有几个飞马牧场的弟子正在那里放牧养马。往西
北走就是飞马牧场的内堡了。
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"door",
	  "southeast":__DIR__"huayuan1",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

