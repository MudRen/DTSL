
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƪ");
  set ("long", @LONG
��ϲ�㣡�����������Ӵ���ѧԺ��ҵ�ˣ����ｫ�Ὣ�����һЩ
�������ʵĶ����ˣ��쵽���Ե�С��ȥ�����ɣ�
LONG);

  set("exits", ([ 
 "east":__DIR__"room14",
 "west":__DIR__"room15",
 "north":__DIR__"room16",
 "south":__DIR__"room10",
        ]));
  
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

