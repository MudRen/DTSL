
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·����������˺��١���˵���ﾭ����ǿ�˳�û����
����С��������
LONG);

  set("exits", ([ 

  "northeast":__DIR__"shalu1",
  "west":__DIR__"shulin1",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

