
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","�䳡");
  set ("long", @LONG
�����Ǻ�ɳ����䳡���м�����ɳ�������������ϰ���գ���ǹŪ
�����ò����硣
LONG);

  set("exits", ([ 
  "southwest":__DIR__"xiaolu2",
      ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

