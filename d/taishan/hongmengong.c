
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","红门宫");
  set ("long", @LONG
这里是泰山的红门宫。走到这里，你不禁有些疲惫了。向上望去，
还有很多的山路要走，泰山的顶峰还是遥不可及。
LONG);

  set("exits", ([ 

   "westup":__DIR__"shanlu3",
   "down":__DIR__"shanlu2",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();

}