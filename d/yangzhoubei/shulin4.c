
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֡���Ƭ���ֿ������ܴ��ϱ���һ��ɽ·�������
���˶�һЩ��
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shulin3",
 "south":__DIR__"shanlu12",
        ]));
  set("objects",([
     __DIR__"npc/she":2,
     ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

