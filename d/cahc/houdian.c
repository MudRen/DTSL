
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
������Ҵͥ���ĺ������в�������¥�󣬶�����������ھ���
��ס�ĵط������������ʹ���������գ�������װ��Ů��̫��������ʰ
���䡣
LONG);

  set("exits", ([ 
 "northdown":__DIR__"qingshilu1",
 "south":__DIR__"tiancedian",
 "eastdown":__DIR__"tongmingmen",
        ]));
    set("objects",([
        __DIR__"npc/shinv":1,
    ]));
  
  
  set("valid_startroom", 1);
  setup();
 
}

