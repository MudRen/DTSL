
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������С·��·���������˺ܶ����������ܴ����ܲ����ʻ��̲�
�������֣�����ɽ���ﴵ����������磬������������������һЩ����
�Ļ��㣬���߾��������ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"nanan2",
 "west":__DIR__"xiaolu2",
 "north":__DIR__"baiti",
        ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

