
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ĳ�");
  set ("long", @long
������ֹ���Թۿ��赸�������ԶĲ����������һ�����µĶĳ���
long);

  set("exits", ([ 
 "south":__DIR__"chuancang",
 "north":__DIR__"chuancang2",
 
        ]));
 set("objects",([
	 __DIR__"npc/yahuan1":2,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

