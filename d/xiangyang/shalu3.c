
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
������һ��ɳʯ·���ϱ���һƬ���֡�ż��������������ҴҶ�
����·����һ������ľ�����С�ݡ�
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shalu2",
  "south":__DIR__"tree1",
  "northeast":"/d/baling/lu1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

