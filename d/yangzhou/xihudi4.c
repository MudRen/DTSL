
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
 "south":__DIR__"xihudi3",
 "northeast":__DIR__"guangchang",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

