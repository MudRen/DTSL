
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݴ�");
  set ("long", @LONG
������һƬ�ݴԡ��ݸ߹���ͷ�������ֲ���������������
LONG);

  set("exits",([
	  "northwest":__DIR__"caocong1",
	  "southeast":__DIR__"caocong2",
	  "north":__DIR__"caocong2",
	  "out":__DIR__"cunxi",

	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

