
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С�š������кܶ����������ȥ��������һ����԰���м�
���μұ��ĵ�������������Ϣ�����еؿ�������ˮ�е����㡣��ʱ�м�
�����Ӵ���������߹���
LONG);

  set("exits", ([ 

      "northeast":__DIR__"xilang2",
	  "west":__DIR__"huayuan2",
       ]));
  set("objects",([
	  "/d/clone/npc/chenzhifo":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

