
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�������������������������Ʒ����٣�������ʯ�壬ɽ����ʣ�
��һ��������������������أ���ν���Ʒ�֮������
LONG);

  set("exits", ([ 
 "northeast":__DIR__"baiyun-feng",
 "southwest":__DIR__"tiyun-feng",
         ]));
  set("objects",([
   __DIR__"npc/gongzi":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

