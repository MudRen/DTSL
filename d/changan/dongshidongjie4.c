
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
�����������������Ķ��У������У������Ƕ����еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���
LONG);

  set("exits", ([ 
  "north":__DIR__"dongshidongjie3",
  "south":__DIR__"dongshidongjie5",
  "west":__DIR__"dongshixijie4",
  "east":__DIR__"dongshidongkou2",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

