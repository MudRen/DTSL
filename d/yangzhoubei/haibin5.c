
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǻ������ϱ���ãã�Ĵ󺣡����ڵķ�ܴ󣬺��˲�ʱ������
�˵����ߣ�Զ�����Կ��������㴬��������㡣
LONG);

  set("exits", ([ 
 "east":__DIR__"haibin6",
 "southwest":__DIR__"haibin4",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

