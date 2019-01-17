
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
你走在一条山路上，南边就是武夷山的上山之路了。放眼望去，武
夷山秀丽的景色尽收眼底。前面有一条小溪，东边有一片树林，好象有
人正在那里观赏风景。
LONG);

  set("exits", ([ 

   "southup":__DIR__"xiaoxi1",
   "northdown":__DIR__"shanlu1",
   "east":__DIR__"shulin2",
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

