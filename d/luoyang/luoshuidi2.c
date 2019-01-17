
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ÂåË®µÌ");
  set ("long", @long
ÂåË®µÌ±ßÔÓÖ²»±Áø£¬Ê÷ÂÌ³ÉÒñ£¬·ç¾°ÃÔÈË¡£
long);

  set("exits", ([ 
  
  "north":__DIR__"tianjinqiao3",
  "west":__DIR__"luoshuidi1",
  "east":__DIR__"luoshuidi3",
  "south":__DIR__"baihujie1",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

