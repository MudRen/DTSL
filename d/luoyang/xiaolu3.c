
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里的人已经很少了。但由于洛阳的治安很好，所以这里没有什么
危险。
LONG);

  set("exits", ([ 
	  "northeast":__DIR__"xiaolu4",
	  "west":__DIR__"xiaolu2",
  
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

