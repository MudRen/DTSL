
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
���������������������У������У������������е����֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ���ʻ��꣬��
����һ��Ǯׯ��
LONG);

  set("exits", ([ 
  "north":__DIR__"xishixijie4",
  "south":__DIR__"xishinankou1",
 "west":__DIR__"huadian1",
 "east":__DIR__"qianzhuang1",
        ]));
  set("objects",([
         __DIR__"npc/liumang":2,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

