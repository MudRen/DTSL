
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����������������Ķ��У������У������Ƕ����е����֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ�ҽ����꣬��
����һ�������ꡣ
LONG);

  set("exits", ([ 
  "north":__DIR__"dongshixijie4",
  "south":__DIR__"dongshinankou1",
 "west":__DIR__"yinqidian",
 "east":__DIR__"jinqidian",
        ]));
  set("objects",([
   __DIR__"npc/shusheng":1,
   ]));
   
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

