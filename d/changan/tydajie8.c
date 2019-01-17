
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","通远大街");
  set ("long", @LONG
你走在通远大街上，这条大街横贯长安城东西，东连通化门，西至
开远门，是长安城的主干道之一。四面静悄悄的。南北通向的大街是长
升大街。东面就是通化门。
LONG);

  set("exits", ([
 "south":__DIR__"csdajie3",
 "east":__DIR__"tonghuamen",
 "west":__DIR__"tydajie7",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

