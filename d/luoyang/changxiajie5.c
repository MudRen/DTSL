
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ĵ��");
  set ("long", @long
�����������ĳ��Ľ֡�������������ĳ������ˣ�����������һ��
ҩ�̣����۸ߵ͹�������Խ�ȥץҩ��

long);

  set("exits", ([ 
	  "north":__DIR__"changxiajie4",
  	  "south":__DIR__"nanmen2",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

