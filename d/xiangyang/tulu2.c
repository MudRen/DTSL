
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·���������Ĵ��ľ��ء������߾��Ǻ����ľ����ˡ���
ʱ�м������ɿ��ܹ���
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tulu1",
 "west":"/d/dabashan/shanjiao",
 "north":__DIR__"nongtian",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

