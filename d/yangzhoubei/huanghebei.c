
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghebei"
#define TO __DIR__"huanghenan"
#include "/std/shiproom.c"

void create ()
{
  set ("short","黄河北岸");
  set ("long", @LONG
这里是黄河的北岸。面前是滚滚的黄河，你不禁生出一股豪气。你
可以在叫船家(yell boat)，就可以乘舟到黄河南岸了。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"caodi3",
   "west":"/d/leshou/road6"
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}

