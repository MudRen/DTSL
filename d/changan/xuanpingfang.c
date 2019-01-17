
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","宣平坊");
  set ("long", @LONG
长安城内坊与坊间都以围墙街道分隔，井然有序，每坊四门，主要
街道是以十字形贯通各门的石板路，小巷成方格网状通向坊内主街。坊
内民居多为低矮的砖木房，朴素整齐，院落森树时花，窗明几净，一片
安祥舒适的居住气氛。 
LONG);

  set("exits", ([ 
 "east":__DIR__"wxdajie1",
 "south":__DIR__"shibanlu",
         ]));
  set("objects",([
         __DIR__"npc/baixing":2,
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

