
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǳɶ��ĵ��̡��ϰ������վ�ڹ�̨�󣬶�����������������
���������顣�м�����վ�����������ԥ�Ƿ��������Ķ�����
LONG);

  set("exits", ([ 
 "north":__DIR__"dongdajie1",
        ]));
  set("objects",([
	  __DIR__"npc/huo":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

