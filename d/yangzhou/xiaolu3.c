
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�����߿���ңң�����Ϸʵĳ�ǽ����������˱Ƚ�
���ˣ���������������������Գ۹���
LONG);

  set("exits", ([ 
 "northeast":__DIR__"xiaolu2",
 "west":"/d/hefei/dongmen",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

