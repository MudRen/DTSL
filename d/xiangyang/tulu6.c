
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是一条土路。由于这里战乱连年，所以百姓纷纷逃向北方，显
得人烟稀少。
LONG);

  set("exits", ([ 

  "south":__DIR__"shalu1",
  "northeast":__DIR__"tulu5",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

