
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","ʯ·");
  set ("long", @LONG
������һʯ·����ʱ�м����˺�����������һ��紵��������һ
��ˮ����Ϣ��ż�����������������������
LONG);

  set("exits", ([ 
	  "north":__DIR__"tulu1",
	  "south":__DIR__"caodi",
	  "west":__DIR__"juyitang",
	  "east":__DIR__"shalu",
    ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

