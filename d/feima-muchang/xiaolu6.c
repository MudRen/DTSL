
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"С·"NOR);
  set ("long", @LONG
������һ��С·����ת���䣬��ǰ���ػ�Ȼ���ʣ������µ�̨���ϣ�
����һ������С¥��������Ҫ.
LONG);

  set("exits", ([ 

	  "west":__DIR__"xiaolu5",
	  "east":__DIR__"xiaolou",
  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

