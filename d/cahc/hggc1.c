
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","横贯广场");
  set ("long", @LONG
你走到这里，不禁被这横分南北、气贯东西的长街式广场的磅磺气
势所震慑，叹为观止。整个广场长宽都超百丈，用巨大平整的白色大理
石铺成，东北面就是象征着天子气派的承天门。这里平时几乎没有什么
人，若逢年过节，朝廷会允许百姓在这里举办大型的庆祝活动，届时天
子会登上承天门楼主持。
LONG);

  set("exits", ([ 
 "north":__DIR__"guangyunmen",
 "east":__DIR__"hggc2",
 "west":__DIR__"anfumen",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

