
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������һ��С�����׻�˵���������ã������պ������㲻��Ϊ��Χ
������ɫ�������ˡ�
LONG);

  set("exits", ([ 

  "southwest":__DIR__"xiaojing1",
  "north":__DIR__"caodi1",
        ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

