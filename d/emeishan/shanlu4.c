
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·������ľ�ɫʮ����������ʱ�����˺�����������
�ʻ��̲��������֣�����ɽ���ﴵ����������磬������������������һ
Щ�����Ļ��㡣����·ͨ���üɽ��
LONG);

  set("exits", ([ 
 "westup":__DIR__"shanjiao",
 "eastdown":__DIR__"shanlu5",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

