
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء�����ż������������ײ������������ʱ���˴ӱ�
���߹������û��ɵ��۹�������㡣
LONG);

  set("exits", ([ 

  "northeast":__DIR__"bingqiku",
  "south":__DIR__"xiaolu1",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

