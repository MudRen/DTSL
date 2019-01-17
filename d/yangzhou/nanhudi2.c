
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南湖堤");
  set ("long", @LONG
这里是扬州城的南湖堤。南边传来一些喧哗声，打破了这里的宁静。
这里怪石嶙峋，参差起伏，另有一番风采。再往南就是扬州的南大街了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"donghudi4",
 "southeast":__DIR__"nandajie1",
 "west":__DIR__"nanhudi",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

