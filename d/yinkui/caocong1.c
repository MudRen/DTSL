
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݴ�");
  set ("long", @LONG
������һƬ�ݴԡ��ݸ߹���ͷ�������ֲ���������������
LONG);

  set("exits",([
	  "west":__DIR__"door",
	  "southeast":__DIR__"caocong2",
	  "east":__DIR__"caocong1",

	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

