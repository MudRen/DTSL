
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"��ʦ������2"NOR);
  set ("long", @LONG
��������ʦ������ 2��������Ŵ���˫�������а�����ʦ��Ҫ��
��get��
LONG);

  set("exits", ([ 
 "south":__DIR__"wizroom",
        ]));

  set("valid_startroom", 1);
  setup();
  "/obj/tboard/topc_b.c"->foo();
}


