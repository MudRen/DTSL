
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭ�ݵأ�������㡣���������������Щ���ˡ�����羰
������ɽˮ�续���������¡���ʱ����������ͷ�Ϸɹ���
LONG);

  set("exits", ([ 

  "north":__DIR__"shanlu6",
        ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

