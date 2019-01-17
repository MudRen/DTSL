
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","通远桥");
  set ("long", @LONG
这是一座白色的石桥，跨越在南北流向的永安渠之上，这里人来人
往，显得十分热闹，再向东去，就能到达长安著名的娱乐场所了。
LONG);

  set("exits", ([ 
  "westdown":__DIR__"tydajie1",
  "eastdown":__DIR__"tydajie2",
        ]));
  set("objects",([
	  __DIR__"npc/xiaojie":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

