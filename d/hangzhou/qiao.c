
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��");
  set ("long", @LONG
������һ�����ϣ�����������������������ķ�⡣���²�����С
����������ˮ����������һ�澵�ӣ��������¡�
LONG);

  set("exits", ([ 
 "northdown":__DIR__"dongan1",
 "southdown":__DIR__"nanan2",
        ]));
  set("objects",([
	  __DIR__"npc/beauty":1,
	  "/d/clone/npc/yunyuzhen":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

