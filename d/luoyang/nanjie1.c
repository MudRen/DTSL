
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南天街");
  set ("long", @long
这里是洛阳的南天街。北面是洛阳的新中桥。这里可以听到北面热
闹的声音。
long);

  set("exits", ([ 
	  "north":__DIR__"tianjie4",
	  "east":__DIR__"shuyuan",	  
  	  "south":__DIR__"nanjie2",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

