
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"南门"NOR);
  set ("long", @LONG
这里是杭州的南门。杭州是旅游胜地，所以这里的行人很多。这里
有两个官兵，在检查着来往的行人。
LONG);

  set("exits", ([ 

  "north":__DIR__"nandajie2",
  "south":"/d/dongming/dalu4",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

