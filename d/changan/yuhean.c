

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","玉鹤庵");
  set ("long", @LONG
走着走着，倏地豁然开朗，一座规模只有东大寺四分之一大小的庙
堂出现眼前，朴实无华，予人躲避俗尘的清幽感受。门上写着"玉鹤庵"
三个清秀挺拔的字。
LONG);

  set("exits", ([ 
 "south":__DIR__"xiaojing",
]));
  
  set("valid_startroom", 1);
  setup();
 
}
