
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
�������μұ��������ˡ���������һ�����ң������������֡��μ�
�������ʻ����������ƺ��е��������������������μұ������ɡ�����
��ǰ������һ�Ѵ����ӣ����Ը�����һ��С���ӡ������������£��ǳ�
�ž���
LONG);

  set("exits", ([ 

  "north":__DIR__"changlang2",
  "west":__DIR__"xilang1",
  "east":__DIR__"donglang1",
"up":"/d/clone/room/lingwu/lingnan/baihutang",
  "southwest":__DIR__"changlang3",
  "southeast":__DIR__"yuedongmen",
        ]));

  set("valid_startroom", 1);
  
  setup();
  "/obj/sboard/songjia_b.c"->foo();
 
}

