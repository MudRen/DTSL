
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������Ĵ�·������������������ĳ�ǽ�ˡ�����������·��
����������Ѿ��ܶ��ˡ�
LONG);

  set("exits", ([ 

  "northeast":__DIR__"dalu1",
  "southwest":"/d/xiangyang/guanlu2",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

