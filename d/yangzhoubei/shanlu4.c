
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·������ĵ��θ�����Ҫ���Ա��кܶ�ɽ�ȣ�����ȥ
���Ƿ�������ˡ�������̩ɽ�ˣ�ԶԶ���Կ���̩ɽ���ʵ�ɽ�塣
LONG);

  set("exits", ([ 
 "north":__DIR__"taishanjiao",
 "southeast":__DIR__"shanlu3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

