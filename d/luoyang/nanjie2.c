
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @long
����������������֡������������������š������������������
�ֵ�������
long);

  set("exits", ([ 
	  "north":__DIR__"nanjie1",
      "east":__DIR__"liangchang",
  	  "south":__DIR__"nanjie3",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

