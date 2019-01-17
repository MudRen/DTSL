
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长安钱庄");
  set ("long", @LONG
这家钱庄据说是来自中原的一位退位高官所开，在全国各地开了不
少分店。因为谣言，曾经有过一次挤兑风潮，钱庄一一兑付，不欠分毫。
如今名气大震，发行的银票通行全国。
LONG);

  set("exits", ([ 
 "west":__DIR__"dongshixijie1",
        ]));
  set("objects",([
	  __DIR__"npc/qian":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

