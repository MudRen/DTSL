
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","行宫");
  set ("long", @LONG
这里就是李渊在终南山上行猎住的行宫，里面屋宇楼阁，气势非凡。
由于这里是皇帝的行宫，只有行猎时李渊才要在这里办公，平常守卫不
是很严，但平常百姓是不得接近行宫的。
LONG);

  set("exits", ([ 
 "west":__DIR__"shangu",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

