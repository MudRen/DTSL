
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
���������������������У������У������������е����֣�������
��ǰ���伯�е��ˡ�ߺ�����������������ڶ���������һ�Ҿ�¥������
��һ���䱦����ꡣ
LONG);

  set("exits", ([ 
  "north":__DIR__"xishibeikou1",
  "south":__DIR__"xishixijie2",
 "west":__DIR__"zhenbaozhai",
 "east":__DIR__"zhangjialou",
        ]));
  set("objects",([
         __DIR__"npc/shangren":2,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

