
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�̹�");
  set ("long", @LONG
�������̹ݣ����ص������������̾�ס�ĵط���
LONG);

  set("exits", ([ 
      "west":__DIR__"qinglongjie2",
  ]));
  set("valid_startroom", 1);
  setup();
 
}