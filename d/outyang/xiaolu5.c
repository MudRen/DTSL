
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·������Ϳ쵽����ˡ���������˽����Ķ�������
��ʱ���ܿ���һЩ��������������ʿ��������Գ۹���
LONG);

  set("exits", ([ 
 "southwest":__DIR__"xiaolu2",
 "northeast": "/d/yangzhoubei/shanlu13",
 
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

