
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
���������֣������ľ�����������һ�����ʵĸо���������һ����
�ȣ�������һ��������
LONG);

  set("exits", ([ 

	  "west":__DIR__"huilang4",
	  "east":__DIR__"fangting",
  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

