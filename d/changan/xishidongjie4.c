
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
���������������������У������У������������еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���
LONG);

  set("exits", ([ 
  "north":__DIR__"xishidongjie3",
  "south":__DIR__"xishidongjie5",
  "west":__DIR__"xishixijie4",
  "eastup":__DIR__"ymqiao",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

