
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIY"����¥"NOR);
  set ("long", @LONG
�����������ʳǵ�����¥���ǻʹ��ķ����Խ�����
LONG);

  set("exits", ([ 
  "northdown":__DIR__"westdoor",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

