
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����������ڵ�һ��С·�����ﾲ���ĵġ�û�кܴ�����졣ż
��ֻ�����������Ż���������
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaolu2",
  "south":__DIR__"xiuxishi",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

