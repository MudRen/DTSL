
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�����߲�Զ��������ʦ�ˡ���ʱ��������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaoxi2",
 "west":__DIR__"xiaolu4",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

