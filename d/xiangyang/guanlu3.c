
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������ǵ�������Ĺ�·��������˲��Ǻܶ��ˡ�����ĵ�·
�ǳ��������ܾ�ɫ��������ʱ�д�ӵĹٱ�����������߹�����ͷ��
���첻ʱ��ͷ�������㡣
LONG);

  set("exits", ([ 
 "north":__DIR__"nanmen",
 "south":__DIR__"guanlu4",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

