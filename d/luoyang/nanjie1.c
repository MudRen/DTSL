
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
	  "north":__DIR__"tianjie4",
	  "east":__DIR__"shuyuan",	  
  	  "south":__DIR__"nanjie2",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

