
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������һ���ľ���С���������������ɳ��ϱ߲����������ˡ�ƽʱ
�������������ֻ�д�ɨ���ҵĵ��Ӵ����ﾭ����
LONG);
  set("exits",([
	  "west":__DIR__"woshi1",
	  "south":__DIR__"caodi",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

