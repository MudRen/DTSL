
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵء���������ԼԼ������ߺ�ȵ���������������ϰ��
�յ����������ﲻʱ���˳��롣
LONG);

  set("exits", ([ 
	  "north":__DIR__"shilu",
	  "south":__DIR__"mumen",
	  "west":__DIR__"wuchang",
	  "east":__DIR__"zhifatang",
    ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

