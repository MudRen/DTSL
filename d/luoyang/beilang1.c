
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
�����Ǳ��ȡ��������߾��ǻʵ۵��޹��ˡ�����ƽ�������ǲ�����
���ˡ�����ǳ��ž��������������ľ�����ݣ�������������㡣��ʱ
��̫���ȥ������ͨ�����顣
LONG);

  set("exits", ([ 
  
  "north":__DIR__"changlang",
  "south":__DIR__"qingshilu3",

         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

