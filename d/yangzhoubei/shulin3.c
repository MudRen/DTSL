
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֡���Ƭ���ֿ������ܴ󡣾�˵���ֵط��������е�
����û���㲻���ӿ����н��ĽŲ���
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu11",
 "southwest":__DIR__"shulin4",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

