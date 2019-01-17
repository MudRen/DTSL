
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ÂåË®µÌ");
  set ("long", @long
ÂåË®µÌ±ßÔÓÖ²»±Áø£¬Ê÷ÂÌ³ÉÒñ£¬·ç¾°ÃÔÈË¡£
long);

  set("exits", ([ 
  

  "west":__DIR__"xibianmen2",
  "east":__DIR__"luoshuidi2",
  "south":__DIR__"pigedian",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

