
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�������Ѿ��ǰ��յľ����ˡ��������߾Ϳ��Ե���
���ˡ�Զ�������п޺�����������֪���ĸ������б��ٱ�������ϴ���ˡ�
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"xiaolu1",
 "southwest":__DIR__"xiaolu3",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

