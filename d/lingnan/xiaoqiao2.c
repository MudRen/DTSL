
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
�����Ǹ�С�š�������ˮ�������죬�����������泩���м����μ�
���ĵ�������������Ϣ�����еؿ�������ˮ�е����㡣��ʱ�м�������
����������߹���
LONG);

  set("exits", ([ 

  "east":__DIR__"huayuan1",
  "southwest":__DIR__"xiaolu",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

