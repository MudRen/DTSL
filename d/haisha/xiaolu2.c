
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����������ڵ�һ��С·��������ȥ��һƬ�����ľ�ɫ�����߲�
ʱ����һ����ߺ�ȵ���������������������ϰ���ա�
LONG);

  set("exits", ([ 

  "west":__DIR__"xiaolu1",
  "east":__DIR__"xiaolu3",
  "northeast":__DIR__"wuchang",
  "south":__DIR__"xiaolu4",
       ]));
  set("objects",([
	  __DIR__"npc/yangzhen":1,
	  ]));
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

