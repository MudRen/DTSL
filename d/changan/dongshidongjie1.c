
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
�����������������Ķ��У������У������Ƕ����еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ���ξ֣�����
��һ�ҵ��̡�
LONG);

  set("exits", ([ 
  "north":__DIR__"dongshibeikou1",
  "south":__DIR__"dongshidongjie2",
 "west":__DIR__"dangpu1",
 "east":__DIR__"yanju",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

