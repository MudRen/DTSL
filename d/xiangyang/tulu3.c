
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·���������Ĵ��ľ��ء������߾Ϳ��Ե��ɶ��ˡ���ʱ
�м������ɿ��ܹ���
LONG);

  set("exits", ([ 
 "east":"/d/dabashan/shanlu5",
 "west":__DIR__"tulu4",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

