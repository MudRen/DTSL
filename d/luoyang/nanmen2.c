
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"������"NOR);
  set ("long", @LONG
���������������ŵı��š�������Ҳ���Խ��������ǡ�
LONG);

  set("exits", ([ 
  	  "southeast":"/d/outyang/guanlu1",
	  "north":__DIR__"changxiajie5",
	  "northeast":__DIR__"xiaolu1",
  "west":__DIR__"nanmen",
       ]));
  set("objects",([
	  __DIR__"npc/bing":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

