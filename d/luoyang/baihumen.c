
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�׻���"NOR);
  set ("long", @LONG
�����������İ׻��š���������Գ��������ˡ�����������������
�š�
LONG);

  set("exits", ([ 
  

  "northwest":__DIR__"baihujie4",
  "east":__DIR__"nanmen",
  "south":__DIR__"guanlu1",

         ]));
  set("objects",([
	  __DIR__"npc/bing":1,
	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

