
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
�����Ǹ�С�š��ϱ���һ�����֡������кܶ����������ȥ���м�
���μұ��ĵ�������������Ϣ�����еؿ�������ˮ�е����㡣��ʱ�м�
�����Ӵ���������߹���
LONG);

  set("exits", ([ 

  "northeast":__DIR__"huayuan1",
 "southwest":__DIR__"zhulin",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

