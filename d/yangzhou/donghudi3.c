
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵĶ����̡����ߴ���һЩ�������������������������
LONG);

  set("exits", ([ 
 "north":__DIR__"donghudi2",
 "south":__DIR__"donghudi4",
 "southeast":__DIR__"dongdajie1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

