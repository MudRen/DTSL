
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
���������������������У������У������������еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ��������ǳ��������ľ�¥
--����¥��������һ���ر��ΰ�Ľ����
LONG);

  set("exits", ([ 
  "north":__DIR__"xishidongjie2",
  "south":__DIR__"xishidongjie4",
  "west":__DIR__"xishishu",
  "east":__DIR__"fujulou",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

