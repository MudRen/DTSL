
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·��������һƬ���֣�������ǻ����ˡ����������
���Ǻܶࡣ
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shulin2",
 "northeast":__DIR__"shulin4",
 "southeast":__DIR__"huaihebei",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

