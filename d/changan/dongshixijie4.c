
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����������������Ķ��У������У������Ƕ����е����֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���
LONG);

  set("exits", ([ 
  "north":__DIR__"dongshixijie3",
  "south":__DIR__"dongshixijie5",
  "west":__DIR__"dongshixikou2",
  "east":__DIR__"dongshidongjie4",
        ]));
  set("objects",([
   __DIR__"npc/gongzi":1,
   ]));
   
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

