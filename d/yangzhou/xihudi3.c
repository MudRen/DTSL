
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵ������̡�����ͣ���ż����Ѿ��޲��õĻ�����������
���Ĵ����������ԣ������Ϣ�š�
LONG);

  set("exits", ([
 "southwest":__DIR__"xihudi2",
 "north":__DIR__"xihudi4",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

