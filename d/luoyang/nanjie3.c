
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南天街");
  set ("long", @LONG
这里是洛阳的南天街。北面是新中桥，可以看到有许多游人在上面
欣赏着洛阳的风光。西面有一个兵器店，从那里传来乒乒乓乓的敲打兵
器的声音。
LONG);

  set("exits", ([ 
	  "north":__DIR__"nanjie2",
	  "west":__DIR__"bingqidian",
  	  "south":__DIR__"nanjie4",

         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

