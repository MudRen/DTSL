
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","碎石路");
  set ("long", @LONG
这里是一条碎石路，道路宽敞。这里是大江联英雄们练习武艺和休
息的地方。西边是一个练武场，东边是一个厨房。不时有大江联弟子从
这里走过。
LONG);

  set("exits", ([ 
 "out":__DIR__"juyitang",
 "westdown":__DIR__"lianwuchang",
 "east":__DIR__"chufang",
 "northdown":__DIR__"caodi",
      ]));
  set("valid_startroom", 1);
  set("outdoors","dajianglian");
  setup();
 
}
