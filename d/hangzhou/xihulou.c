
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖楼");
  set ("long", @LONG
这里是杭州著名的酒楼--西湖楼。由于杭州的游客一直很多，所以
酒楼的生意很好。由于酒楼地处西湖岸边，所以取名「西湖楼」。店小
二总是忙个不停。
LONG);

  set("exits", ([ 
"south":__DIR__"xidajie1",
         ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));
 
  set("valid_startroom", 1);
  setup();
 
}

