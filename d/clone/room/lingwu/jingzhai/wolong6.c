
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","游龙峰");
  set ("long", @LONG
这里就是卧龙岭上的游龙峰，这里地势狭长，两旁是陡峭的悬崖。
向西北望去，可以远远望到卧龙岭的浮云坪和飞天崖，从这里看去，飞
天崖深不见底，只有几棵生长在崖边的松树在浮云中若隐若现，随风而
动。
LONG);

  set("exits", ([ 
 "westdown":__DIR__"wolong5",
 "eastdown":__DIR__"wolong7",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

