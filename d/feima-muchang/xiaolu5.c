
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"小路"NOR);
  set ("long", @LONG
这里是一条碎石小路，与方亭连接，沿着崖边延往林木深处，令人
兴起寻幽探胜之心.
LONG);

  set("exits", ([ 

	  "northwest":__DIR__"fangting",
	  "east":__DIR__"xiaolu6",
  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

