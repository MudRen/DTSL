
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片树林。这片树林看起来很大。据说这种地方最容易有盗
贼出没，你不禁加快了行进的脚步。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu11",
 "southwest":__DIR__"shulin4",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

