
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������ǵ�������Ĺ�·������Ϳ��Ե������ı����ˡ��к�
�೵��������ȥ��һ�����ֵľ������･����������������ʱ�д�
�ӵĹٱ�����������߹���
LONG);

  set("exits", ([ 
 "north":__DIR__"guanlu3",
 "south":__DIR__"xiaolu1",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

