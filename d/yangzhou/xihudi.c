
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵ������̡����ߴ���һЩ��������������Ҫ���޲���
�ֻ����ĵط�������˵�������ݶ����̻������Ѳ�����ϵ��
LONG);

  set("exits", ([ 
 "southeast":__DIR__"nanhudi",
 "north":__DIR__"xihudi2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

