
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
����ľ�ɫʮ����������ʱ�����˺������������ʻ��̲�������
�֣�����ɽ���ﴵ����������磬������������������һЩ�����Ļ��㡣
������·��ȥ�����Ƕ�üɽ�ˡ�
LONG);

  set("exits", ([ 
 "westup":__DIR__"shanlu4",
 "eastdown":"/d/chengdu/tulu2",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

