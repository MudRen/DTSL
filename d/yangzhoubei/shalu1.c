
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳ·");
  set ("long", @LONG
������һ��ɳ·��һ��紵������������Ļ�ɳ����ʱ�йٱ�����
���۶�����������Ҫ�����ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu3",
 "northwest":__DIR__"shalu2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

