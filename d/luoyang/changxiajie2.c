
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ĵ��");
  set ("long", @long
�����������ĳ��Ľ֡�����Ƚϼž���������һ����վ��ż������
��ƥ��˻������

long);

  set("exits", ([ 
	  "north":__DIR__"changxiajie1",
	  "west":__DIR__"yizhan",
  	  "south":__DIR__"changxiajie3",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

