
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����ǳ����ĵ��̡��ϰ������վ�ڹ�̨�󣬶�����������������
���������顣�м�����վ�����������ԥ�Ƿ��������Ķ�����
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshidongjie1",
        ]));
  set("objects",([
	  __DIR__"npc/tie":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

