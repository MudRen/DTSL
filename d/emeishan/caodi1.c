
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭ�ݵء�������ʯ���ˡ�����������£�������Χ�ľ�ɫ��
����������������������������ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"shilin",
 "southwest":__DIR__"xiaojing2",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

