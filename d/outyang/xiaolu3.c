
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·���ϱ߾��ǰ��պͽ��յĽ����ˡ���������˲���
�ܶࡣ��ʱ�����������������Գ۹���
LONG);

  set("exits", ([ 
 "northwest":__DIR__"xiaolu2",
 "southeast":__DIR__"xiaolu4",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

