
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��̧ͷ��ȥ�����߾���һ����������������
�ܴ󣬵������ַ�Χ�У��Եó�������һ�㡣
LONG);

  set("exits", ([ 
 "down":__DIR__"shanlu4",
 "northup":"/d/jingzhai/door",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

