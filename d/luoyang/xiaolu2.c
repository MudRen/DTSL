
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�������������ϵĽ�������������Ե������ľ�����Ժ���������
���١�ֻ�м����������������
LONG);

  set("exits", ([ 
	  "east":__DIR__"xiaolu3",
	  "west":__DIR__"xiaolu1",
  
         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

