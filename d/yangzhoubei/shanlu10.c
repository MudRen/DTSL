
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·��������һƬ���֡���֪��������û�е��������߲�
Զ���ǳ���ɽ�ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"shulin2",
 "northwest":__DIR__"shanlu9",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

