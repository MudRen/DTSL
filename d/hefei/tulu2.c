
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。这里是安徽和湖北的交界，西边就是湖北的境地了，
东边是安徽的境地。
LONG);

  set("exits", ([ 

  "east":__DIR__"tulu1",
  "southwest":__DIR__"caodi1",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

