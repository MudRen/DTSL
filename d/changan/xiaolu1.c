
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","西城外小路");
  set ("long", @LONG
这里是一条沿着长安城墙的林荫小路，这里没有什么人，非常幽静，
只能听到鸟儿清脆的叫声。身旁是高高的城墙，城墙里面就是长安城了。
抬头望去，隐隐约约可以看见一些全副武装的官兵们在城头一丝不苟的站
岗值勤。
LONG);

  set("exits", ([ 
"north":__DIR__"kaiyuanmen",
"south":__DIR__"ximen",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

