
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����ط�");
  set ("long", @LONG
�����������ط��������ٽֵĶ���һ������լ���̹ݣ���Ҫ�ṩ��
�������������Ĺ�Ա�����˾�ס��
LONG);

  set("exits", ([ 
      "east":__DIR__"shangguan1",
      "west":__DIR__"guanzhai1",  
      "north":__DIR__"qinglongjie3",
  "south":__DIR__"qinglongjie1",
         ]));
  set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

