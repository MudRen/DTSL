
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"С·"NOR);
  set ("long", @LONG
������һ����ʯС·���뷽ͤ���ӣ������±�������ľ�������
����Ѱ��̽ʤ֮��.
LONG);

  set("exits", ([ 

	  "northwest":__DIR__"fangting",
	  "east":__DIR__"xiaolu6",
  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

