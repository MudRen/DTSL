
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","ɳ·");
  set ("long", @LONG
������һ��ɳ·��������˺��٣����ܷǳ��ž������������ߣ���
�Ƿֶ����Ϣ���ˡ�
LONG);

  set("exits", ([ 
	  "west":__DIR__"shilu",
	  "east":__DIR__"xiuxishi",
	     ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

