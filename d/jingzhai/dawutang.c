
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"大悟堂"NOR);
  set ("long", @LONG
这里是慈航静斋的大悟堂。慈航静斋的弟子来这里修炼悟性。但是
谁又能真正的大彻大悟，所以这里的修行是很辛苦的。
LONG);

  set("exits", ([ 
  "south":__DIR__"siguotang",
   ]));
  set("objects",([
	  __DIR__"npc/shi":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

