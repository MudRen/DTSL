
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����������������Ķ��У������У������Ƕ����е����֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ��Ǯׯ����
����һ�����С�
LONG);

  set("exits", ([ 
  "north":__DIR__"dongshibeikou2",
  "south":__DIR__"dongshixijie2",
 "west":__DIR__"xingchanglong",
 "east":__DIR__"qianzhuang",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

