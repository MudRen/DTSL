
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是片树林。这里的树木不是很茂盛。仔细看看，似乎有刚刚被
烧过的痕迹，看来这里刚刚发生过一场战斗。东边就是长白山的脚下了。
LONG);

  set("exits", ([ 
 "east":__DIR__"cbsjiao",
 "west":__DIR__"shanlu10",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

