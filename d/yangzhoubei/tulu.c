
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。西边是海滨。一阵风吹来，夹带着咸涩的气息。这
里已经是北方了，天气有些冷了。
LONG);

  set("exits", ([ 
 "west":__DIR__"haibin7",
 "northeast":__DIR__"shanlu7",
 "south":"/d/gaoli/jiangbei",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

