
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
���������������������У������У������������еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ��ˮ���꣬��
����һ�����С�
LONG);

  set("exits", ([ 
  "north":__DIR__"xishidongjie4",
  "south":__DIR__"xishinankou2",
  "west":__DIR__"guangshenghang",
  "east":__DIR__"shuiguodian",
        ]));
  set("objects",([
         __DIR__"npc/xiaojie":1,
         
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

