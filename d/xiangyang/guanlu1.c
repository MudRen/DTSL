
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������ǵĶ�����Ĺ�·���������������ǳ���æ����ʱ����
������ҴҶ��������������˶�Ҫ�ܵ��ϸ�ļ�顣
LONG);

  set("exits", ([ 
"west":__DIR__"dongmen",
"east":__DIR__"guanlu2",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

