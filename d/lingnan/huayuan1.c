
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�����Ǹ���԰��������ֲ�˸��ֻ��ݣ�����������ͷף�������Ŀ��
Ⱥ�����涷�ޣ����࿪�š��м����������������޼��Ż��ݡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"changlang3",
  "west":__DIR__"xiaoqiao2",
  "southwest":__DIR__"xiaoqiao1",
       ]));
  set("objects",([
	  __DIR__"npc/yahuan":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

