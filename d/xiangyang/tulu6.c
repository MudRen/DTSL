
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·����������ս�����꣬���԰��շ׷����򱱷�����
������ϡ�١�
LONG);

  set("exits", ([ 

  "south":__DIR__"shalu1",
  "northeast":__DIR__"tulu5",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

