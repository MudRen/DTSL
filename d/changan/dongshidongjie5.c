
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
�����������������Ķ��У������У������Ƕ����еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ���ӻ��̣���
���ǳ�����
LONG);

  set("exits", ([ 
  "north":__DIR__"dongshidongjie4",
  "south":__DIR__"dongshinankou2",
 "west":__DIR__"chenghuangmiao",
 "east":__DIR__"zahuopu",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

