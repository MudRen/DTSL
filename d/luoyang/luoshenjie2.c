
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����������������֡������������˷��������������߿��Ե���
���š��������߾��������������ˡ�
LONG);

  set("exits", ([ 
  

  "north":__DIR__"qinglongjie1",
  "east":__DIR__"luoshenjie3",
  "west":__DIR__"luoshenjie1",
  "south":__DIR__"tianjinqiao1",
         ]));
  /*set("objects",([
	  "/d/clone/npc/dugu-sheng":1,
	  ]));*/
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

