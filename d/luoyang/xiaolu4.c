
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里可以听到净念禅院的钟声和念经的声音。据说和氏璧就放在净
念禅院，但由于有慈航静斋和宁道奇，所以没有人来敢抢夺。
LONG);

  set("exits", ([ 
	  "east":"/d/chanyuan/miaodoor",
	  "southwest":__DIR__"xiaolu3",
  
         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

