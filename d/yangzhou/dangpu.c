
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ݵĵ��̡��ϰ������վ�ڹ�̨�󣬶�����������������
���������顣�м�����վ�����������ԥ�Ƿ��������Ķ�����
LONG);

  set("exits", ([ 
 "east":__DIR__"beidajie1",
        ]));
  set("objects",([
	  __DIR__"npc/sun":1,
	  ]));
  
  set("valid_startroom", 1);
  set("no_fight", 1);
  setup();
 
}

