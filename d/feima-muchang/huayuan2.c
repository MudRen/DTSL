
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"花园"NOR);
  set ("long", @LONG
这里是花园，最妙是有道周回外廊，延伸往园里去，开拓了景深，
造成游廊穿行于花园的美景之间，左方还有个荷花池，池心建了一座六
角小亭，由一道小桥接连到岸上去。
LONG);

  set("exits", ([ 
	  "east":__DIR__"huilang1",
	  "north":__DIR__"hehuachi",
	  "west":__DIR__"yuedongmen",
    ]));
set("outdoors","feima");
  
  set("valid_startroom", 1);
  setup();
 
}

