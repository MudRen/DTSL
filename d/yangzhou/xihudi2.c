
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖堤");
  set ("long", @LONG
这里是扬州城的西湖堤。这里停靠着几艘已经修补好的花船，三三两
两的船工或坐或卧，随地休息着。
LONG);

  set("exits", ([ 
 "west":__DIR__"xidajie3",
 "south":__DIR__"xihudi",
 "northeast":__DIR__"xihudi3",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

