
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是一条官路。西边就是长安的东门了。这里的行人很多，显得
有些热闹。东边是连绵的山脉。现在是战乱时代，但是长安的李阀治理
有方，所以长安显得非常繁华，来投奔李阀的人也是很多。向北有一条
大路，不知道能通向哪里。
LONG);

  set("exits", ([ 
"west":__DIR__"dongmen",
"east":__DIR__"guanlu2",
"north":__DIR__"dadao1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

