
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是条官路。往南走就可以到襄阳了。不时有武林人士骑着马南
下。
LONG);

  set("exits", ([ 
 "south":__DIR__"beiguanlu1",
 "northwest":__DIR__"shashilu1",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

