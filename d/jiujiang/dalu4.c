
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是个宽敞大路。东边就是扬州的西门了，几乎可以听到城内热
闹的声音。
LONG);

  set("exits", ([ 

  "southeast":"/d/yangzhou/ximen",
  "northwest":__DIR__"dalu3",
  
         ]));
  set("objects",([
	  __DIR__"npc/xiake":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

