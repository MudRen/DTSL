
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ʯ");
  set ("long", @LONG
���Ǿ��Ƕ�üɽ���������ʯ���˴���ʯ�����ݺᣬ������������
��ܽ�أ��·��������ϸ��������
LONG);

  set("exits", ([ 
 "westdown":__DIR__"shanlu6",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

