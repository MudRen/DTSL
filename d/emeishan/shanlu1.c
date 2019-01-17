
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条上山的小路。这里的景色十分秀丽。不时有游人和你擦
肩而过。鲜花绿草若隐若现，随着山谷里吹来的阵阵清风，传来哗哗的
松涛声和一些淡淡的花香。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"shanjiao",
 "westup":__DIR__"shanlu2",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

