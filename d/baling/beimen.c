
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"���걱��"NOR);
  set ("long", @LONG
�����ǰ���ı��š���������˲��١������м����ٱ����ڼ����
���İ��ա��и�����ҫ��������վ�������ͣ��ָ�ֻ��š�
LONG);

  set("exits", ([ 

  "south":__DIR__"qingshilu2",
  "north":__DIR__"guandao1",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

