
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����������ڵ�һ��С·��������ȥ��һƬ�����ľ�ɫ��ż����
����һ����ߺ�ȵ���������������������ϰ���ա�
LONG);

  set("exits", ([ 

  "west":__DIR__"cunxi",
  "east":__DIR__"xiaolu2",
  "north":__DIR__"caodi1",
  "south":__DIR__"caodi2",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

