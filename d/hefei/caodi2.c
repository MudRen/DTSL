
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是片草地。南边就是长江的北岸了。这里风景秀丽，山水如画，
空气清新。江水的潮湿气息扑鼻而来。地上有很多漂亮的野花、蒲公英等
植物。不时有野兔从你的脚旁跳过。
LONG);

  set("exits", ([ 

  "north":__DIR__"shanlu3",
  "south":"/d/jiujiang/jiangbei",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

