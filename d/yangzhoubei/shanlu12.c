
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��������һƬ���֣����ֿ������ܴ������Ѿ���
���յľ����ˡ�������ȥ������ԼԼ���Կ����Ϸʵĳ�ǽ�ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"shulin4",
 "southwest":__DIR__"shanlu13",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

