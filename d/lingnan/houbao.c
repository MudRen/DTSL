
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","后堡门口");
  set ("long", @LONG
这里是宋家堡后堡的门口。宋玉致就是住在后堡了。这里平时没有
人把守，不时有宋家堡的弟子从你身边走过。
LONG);

  set("exits", ([ 

  "north":__DIR__"zhulin",
 "south":__DIR__"xiaojing1",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

