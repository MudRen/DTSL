
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����·");
  set ("long", @LONG
������һ�����Ĵ�·���ϱ߾�Ҫ�����ݵı����ˡ��кܶ೵��
�ϱ���ȥ��һ�����ֵľ��󡣲�ʱ�д�ӵĹٱ�����������߹����ŵ�
·�ϵİ��ն���������ȥ��
LONG);

  set("exits", ([ 
 "north":__DIR__"dalu1",
 "south":__DIR__"guanlu3",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

