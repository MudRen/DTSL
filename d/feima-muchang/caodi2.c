
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء�������Ƿ��������Ĳ�԰�ˡ��м�������������
�������ڳ�������ȥ��������ȥ��԰�ֲ˸ɻ�ġ�
LONG);

  set("exits", ([ 
	  "west":__DIR__"caiyuan",
	  "east":__DIR__"qingshilu3",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

