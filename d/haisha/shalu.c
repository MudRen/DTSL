
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","ɳ·");
  set ("long", @LONG
������һƬϸɳ·��������˲��Ǻܶࡣ���ϱ���ȥ������ԼԼ��
һ�����������ȴû��˿����������
LONG);

  set("exits", ([ 
 "north":__DIR__"caodi2",
  "southeast":__DIR__"juyipeng",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

