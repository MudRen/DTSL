
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·�������Ǻ��ϵľ��ء��������߾Ϳ��Ե������ˡ�
�����߿��Ե������ص������ǡ�
LONG);

  set("exits", ([ 
 "south":__DIR__"shashilu1",
 "north":__DIR__"shashilu3",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

