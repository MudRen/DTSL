
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ͤ");
  set ("long", @LONG
������һ����ͤ������򵥣���������������Ϣ�á�����羰������
ɽˮ�续���������¡�Զ���ĵ����кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ���
ʱ��Ұ�ô���Ľ���������
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu2",
 "west":__DIR__"shanlu3",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

