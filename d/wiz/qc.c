
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"����˫��QC��"NOR);
  set ("long", @LONG
�����Ǵ���˫����QC������������QC�ĵط�����ʦ�������� CLONE
���������ԡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"wizroom2",
        ]));

  set("valid_startroom", 1);
  setup();
 
 "/obj/board/all_post_b.c"->foo();
}


