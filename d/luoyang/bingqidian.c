
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器店");
  set ("long", @LONG
这里是个兵器店。由于是在战乱年代，所以这里的生意特别好。这
里横七竖八地放着各种兵器，长剑、钢刀等。熊熊地炉火烤的脸直发热
。铁匠正在那里敲敲打打，很快就又有一个兵器要出炉了。
LONG);

  set("exits", ([ 

  "east":__DIR__"nanjie3",

         ]));
  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

