
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������Ĵ�·������������Ѿ��ܶ��ˡ���ʱ�����������
��������߹���
LONG);

  set("exits", ([ 

  "northeast":__DIR__"caodi1",
  "southwest":__DIR__"dalu2",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

