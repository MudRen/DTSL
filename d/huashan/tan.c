
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIB"潭水中"NOR);
  set ("long", @LONG
这里是瀑布下面的潭水，上面穿来瀑布水落的轰鸣声，这里却非常
寂静，与上面形成鲜明对比。有几条鱼在你的身旁游来游去。
LONG);

  set("exits", ([ 
 "up":__DIR__"shui",
     ]));
 if(sizeof(children(__DIR__"obj/bifengjian"))<2)
  set("objects",([
	  __DIR__"obj/bifengjian":1,
	  "/d/clone/npc/beast/eyu":1,
	  ]));
set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}

