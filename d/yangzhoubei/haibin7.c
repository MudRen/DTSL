
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǻ�����������ãã�Ĵ󺣡�����������Ǹոմ��������
���ڱ������ң���������徭���⵽�ٱ���������ϴ�٣�����������
�Ǽ�ࡣ
LONG);

  set("exits", ([ 
 "east":__DIR__"tulu",
 "northwest":__DIR__"haibin6",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

