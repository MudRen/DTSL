
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�����Ǹ���԰�������ֵĻ����Ǻܶ࣬��������Ʒ��Ҳ�ǲ��١�
Ⱥ�����涷�ޣ����࿪�š��м����������������޼��Ż��ݡ��ϱ�����
�ұ������������ˣ�������Ѿ�ߴ������߹���
LONG);

  set("exits", ([ 

      "east":__DIR__"xiaoqiao3",
	  "south":__DIR__"woshi1",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

