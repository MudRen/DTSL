
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ����ɽ��С·������ľ�ɫʮ���������ʻ��̲��������֣�
����ɽ���ﴵ����������磬������������������һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 
 "eastup":__DIR__"lianhuashi",
 "northdown":__DIR__"jingxinan",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

