
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
 "north":__DIR__"dongshixijie1",
 "south":__DIR__"dongshixijie3",
 "west":__DIR__"dongshixikou1",
 "east":__DIR__"dongshidongjie2",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

