
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��ֻ��һ�Թٱ�����������߹��������˸߲��ң�
������֪����������ϰ��յ�ù�ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu12",
 "southwest":"/d/outyang/xiaolu5",
 "north":"/d/pengliang/nanchengmen",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

