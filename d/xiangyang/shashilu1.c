
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·����紵����ֻ������Ļ�ɳ���㲻����ס���۾���
�����߿��Ե������ص������ǡ�
LONG);

  set("exits", ([ 
 "southeast":__DIR__"beiguanlu2",
 "north":__DIR__"shashilu2",
 "northwest":__DIR__"shanqiu",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

