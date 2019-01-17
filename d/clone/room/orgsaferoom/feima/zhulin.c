
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","竹林");
  set ("long", @LONG
这里是一片竹林，一片翠绿映入眼帘，让人觉得非常舒服，一身的
疲劳似乎一扫而光。北边是一个卧室，是飞马牧场弟子们休息、睡觉的
地方。
LONG);

  set("exits", ([ 
 "westup":__DIR__"huayuan",
 "northeast":__DIR__"woshi",
 "south":__DIR__"lingwuroom"
      ]));
  set("valid_startroom", 1);
  set("outdoors","dajianglian");
  setup();
 
}
