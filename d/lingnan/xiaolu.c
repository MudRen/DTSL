
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������С·������·��ϸ���Сʯ���̳ɡ��������μұ��ĳ�����
�����ﴫ�������㡣��ʱ���μұ��ĵ��Ӵ��������������
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaoqiao2",
  "west":__DIR__"chufang",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

