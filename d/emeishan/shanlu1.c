
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ����ɽ��С·������ľ�ɫʮ����������ʱ�����˺����
��������ʻ��̲��������֣�����ɽ���ﴵ����������磬����������
��������һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"shanjiao",
 "westup":__DIR__"shanlu2",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

