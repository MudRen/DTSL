
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·��������ǻ��ӵ��ϰ��ˡ���������˲��Ǻܶࡣ
��ʱ�����������������Գ۹���
LONG);

  set("exits", ([ 
 "north":__DIR__"huaihenan",
 "southeast":__DIR__"xiaolu3",
 "northeast":__DIR__"xiaolu5",
 "southwest": "/d/yangzhoubei/dalu1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

