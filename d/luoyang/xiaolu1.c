
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�������������ϵĽ�������������Ե������ľ�����Ժ�����Ｘ��
û��������
LONG);

  set("exits", ([ 
	  "east":__DIR__"xiaolu2",
	  "southwest":__DIR__"nanmen2",
  
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

