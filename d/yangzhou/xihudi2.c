
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
 "west":__DIR__"xidajie3",
 "south":__DIR__"xihudi",
 "northeast":__DIR__"xihudi3",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

