
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����ǳ����ǵ�������Ĺ�·����������������ͨ�������ıؾ�֮
·���������˻��Ǻܶ࣬�������򶫿���Ϳ��Կ����ųǳ����ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"ximen",
 "west":__DIR__"guandao2",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

