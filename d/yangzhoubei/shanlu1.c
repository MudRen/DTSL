
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��������ߣ���������ʧ��������һ��������·
���м�����ʬ���Ѿ����úܾ��ˡ�
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu2",
 "southwest":__DIR__"xiaoxi1",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

