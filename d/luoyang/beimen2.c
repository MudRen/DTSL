
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"永冬门"NOR);
  set ("long", @LONG
这里是洛阳的永冬门，从这里也可以入城。城墙上站着几个士兵，
严厉地看着进出的行人。
LONG);

  set("exits", ([ 

  "southeast":__DIR__"yongdongjie3",
  "west":__DIR__"beimen",
 
  ]));
  set("objects",([
	  __DIR__"npc/bing":1,
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

