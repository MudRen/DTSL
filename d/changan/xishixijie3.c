
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
���������������������У������У������������е����֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ�����У�����
��һ�������̡�
LONG);

  set("exits", ([ 
  "north":__DIR__"xishixijie2",
  "south":__DIR__"xishixijie4",
 "west":__DIR__"baozipu",
 "east":__DIR__"lianghang",
        ]));
  set("objects",([
         __DIR__"npc/youke":2,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

