
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������������·�������Ǻ�������ĳ��������������������
���ܶ��ˡ�
LONG);

  set("exits", ([ 
 "southwest":__DIR__"shashilu3",
 "north":__DIR__"dalu2",
 "northwest":"/d/yinkui/xiaolu3",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

