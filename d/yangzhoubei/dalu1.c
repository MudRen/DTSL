
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ�����Ĵ�·���ϱ߲�Զ���ǺϷ��ˡ���������˽�����
����������ʱ���������������Գ۹���
LONG);

  set("exits", ([ 
 "northeast": "/d/outyang/xiaolu2",
 "southwest":__DIR__"dalu2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

