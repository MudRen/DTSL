
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������ǵĶ�����Ĺ�·���������������ǳ���æ����ʱ����
������ҴҶ�������������������ˡ�
LONG);

  set("exits", ([ 
"west":__DIR__"guanlu1",
"north":__DIR__"caodi2",
"northeast":"/d/hefei/dalu2",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

