
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
������һ��ɳʯ·����紵�������������ɳ����ʱ��������ʿ��
�������
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shulin2",
  "southwest":__DIR__"shashilu2",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

