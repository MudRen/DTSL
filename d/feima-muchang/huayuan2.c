
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"��԰"NOR);
  set ("long", @LONG
�����ǻ�԰���������е��ܻ����ȣ�������԰��ȥ�������˾��
������ȴ����ڻ�԰������֮�䣬�󷽻��и��ɻ��أ����Ľ���һ����
��Сͤ����һ��С�Ž���������ȥ��
LONG);

  set("exits", ([ 
	  "east":__DIR__"huilang1",
	  "north":__DIR__"hehuachi",
	  "west":__DIR__"yuedongmen",
    ]));
set("outdoors","feima");
  
  set("valid_startroom", 1);
  setup();
 
}

