

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
���������£������󷽵�һ��խС��·����������ľ���죬����ֱ
ͨ��΢�����θо��������¹�һ��ѩ��С·������ѩ����������ȷ����
��������߽�С������̤��������ɳɳ����������
LONG);

  set("exits", ([ 
 "west":__DIR__"dongdasi",
 "north":__DIR__"yuhean",
]));
 
 set("outdoors","changan");
    set("valid_startroom", 1);
  setup();
 
}
