
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������������·�����߾��������������ˡ����Ｘ������������
�����ֵ�������
LONG);

  set("exits", ([ 
 "south":__DIR__"dalu1",
 "north":"/d/luoyang/nanmen",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

