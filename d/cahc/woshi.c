
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","休息室");
  set ("long", @LONG
这里是天策府弟子休息的地方。床上的被褥叠得整整齐齐，有几个
弟子正在那里熟睡。你来到这里不禁有些困了。
LONG);

  set("exits", ([ 
	  "east":__DIR__"tcgc",
       ]));

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

