
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","和光大街");
  set ("long", @LONG
这是和光大街，南北连接长安城的光化门和和平坊。街上十分热闹，
人来人往川流不息。东面和西面都是长安城西南的主要居民区。
LONG);

  set("exits", ([ 
 "north":__DIR__"xishixikou2",
 "south":__DIR__"xpdajie1",
 "east":__DIR__"guiyifang",
 "west":__DIR__"hepingfang",
       ]));
  set("objects",([
         __DIR__"npc/gongzi":1,
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

