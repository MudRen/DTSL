
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ����ɽ��С·������ľ�ɫʮ��������������һ����ͤ��
������һƬ���֡��ʻ��̲��������֣�����ɽ���ﴵ����������磬��
����������������һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"shanlu1",
 "west":__DIR__"liangting",
 "north":__DIR__"shulin",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

