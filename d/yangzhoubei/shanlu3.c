
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·�������·�ܶ࣬�߲��ã��ͷǳ�������·�ˡ���
��ϸ����������һ�¡���ʱ���˴���������߹���
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu4",
 "south":__DIR__"shanlu2",
 "southwest":__DIR__"shanlu11",
 "west":__DIR__"shalu1",
        ]));
  set("objects",([
     __DIR__"npc/shangren":1,
     ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

