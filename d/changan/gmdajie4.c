
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","光明大街");
  set ("long", @LONG
你走在光明大街上，这条大街横贯长安城东西，东连春明门，西至
金光门，是长安城的主干道之一。四面静悄悄的。南北通向的大街是安
上大街。
LONG);

  set("exits", ([ 
 "north":__DIR__"asdajie4",
 "south":__DIR__"asdajie3",
 "east":__DIR__"gmdajie3",
 "west":__DIR__"guangchang",
 "northwest":"/d/cahc/anshangmen",
        ]));
  set("objects",([
   __DIR__"npc/xiaojie":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

