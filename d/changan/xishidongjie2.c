
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ж���");
  set ("long", @LONG
���������������������У������У������������еĶ��֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���
LONG);

  set("exits", ([ 
  "north":__DIR__"xishidongjie1",
  "south":__DIR__"xishidongjie3",
  "west":__DIR__"xishixijie2",
  "eastup":__DIR__"fyqiao",
        ]));
  set("objects",([
         __DIR__"npc/haoke":1,
         __DIR__"npc/shangren":1,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

