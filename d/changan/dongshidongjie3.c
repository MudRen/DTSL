
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
�����������������Ķ��У������У������Ƕ����еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ��������ǳ���ʤ�����̸�
������һ�Ҳ�ݡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshidongjie2",
 "south":__DIR__"dongshidongjie4",
 "west":__DIR__"chaguan",
 "east":__DIR__"lingyange",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

