
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"广场"NOR);
  set ("long", @LONG
这里雕栏玉砌，向远处望去，楼宇层叠，巍峨的宫殿数不胜数。这
里经常有官兵来巡逻，很少有人敢在此停留。
LONG);

  set("exits", ([ 
  "west":__DIR__"guangchang2",
         ]));

  set("objects",([
   __DIR__"npc/gongnv1":1,
   ]));
   
  set("valid_startroom", 1);
  setup();
 
}

