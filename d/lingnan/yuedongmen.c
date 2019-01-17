
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","月洞门");
  set ("long", @LONG
这里是月洞门。过了月洞门就是宋家堡弟子习武的地方了。从那里
可以听到阵阵习武呼喝的声音。不是有宋家堡的弟子从那里满头大汗地
走了过来。
LONG);

  set("exits", ([ 

   "northwest":__DIR__"zhengting",
   "east":__DIR__"liangting1",
   "southeast":__DIR__"caodi",
        ]));
  set("objects",([
	  __DIR__"npc/songshidao":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

