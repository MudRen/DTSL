
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
���������������������У������У������������е����֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���
LONG);

  set("exits", ([ 
  "north":__DIR__"xishixijie3",
  "south":__DIR__"xishixijie5",
  "west":__DIR__"xishixikou2",
  "east":__DIR__"xishidongjie4",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

