
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�̹�");
  set ("long", @LONG
�������̹ݣ����ص������������̾�ס�ĵط���
LONG);

  set("exits", ([ 
      "west":__DIR__"qinglongjie3",
  ]));
  set("valid_startroom", 1);
  set("no_fight",1);
  setup();
 
}

