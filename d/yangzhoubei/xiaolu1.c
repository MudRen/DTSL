
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������С·��һ��紵������������������ʱ��������������
���Գ۹�������ȥ��������Լ�������ݵĳ����ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"xiaolu2",
 "south":"/d/outyang/dalu1",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

