
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。西边不远处就是偃师了。不时有两三骑快马从身
边飞驰而过，扬起一路尘埃，道路两旁是整整齐齐的杨树林。
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaoxi2",
 "west":__DIR__"xiaolu4",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

