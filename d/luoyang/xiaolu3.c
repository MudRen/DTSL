
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������Ѿ������ˡ��������������ΰ��ܺã���������û��ʲô
Σ�ա�
LONG);

  set("exits", ([ 
	  "northeast":__DIR__"xiaolu4",
	  "west":__DIR__"xiaolu2",
  
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

