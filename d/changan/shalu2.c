
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","ɳ·");
  set ("long", @LONG
������һ��ɳ·�����������ս�ң�ʱ�����۰׹�ɢ���ڻ�����Ұ
�⡣���������£�����������ż���������ڿ��е�ͺ�ո�����£�̰��
������ʣ�µĸ��⡣
LONG);

  set("exits", ([ 
"northwest":__DIR__"shalu1",
"southeast":__DIR__"lguanlu1",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

