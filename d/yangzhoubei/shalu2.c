
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳ·");
  set ("long", @LONG
������һ��ɳ·���ϱ���һƬ���֡����Ｘ��û���˼�������һƬ
�����ľ��󣬲���֮����Ȼ������
LONG);

  set("exits", ([ 
 "west":"/d/pengliang/dadao2",
 "southeast":__DIR__"shalu1",
 
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

