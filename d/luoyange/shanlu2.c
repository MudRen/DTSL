
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ͨ������ɽ�ϵ�С·�����������Ҫ��ȷʵ�Ǹ�������
���ĵط������������������ķ���������Զ�ˣ���ʱ�����ڸ���������
������������ˡ�
LONG);

  set("exits", ([ 
  "southeast":__DIR__"shanlu1",
  "northwest":__DIR__"caoyuan",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

