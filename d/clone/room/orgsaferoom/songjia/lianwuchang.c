
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
�������μұ������䳡��ֻ����������뱸������÷��׮��ɳ�ӵ�
����Ķ������м����μұ���������������ϰ���գ����ȵ�������ס��
������
LONG);

  set("exits", ([ 
 "southup":__DIR__"changlang1",
 "east":__DIR__"lianwuchang2",
 "west":__DIR__"lianwuchang3",
 "north":__DIR__"lianwuchang4",
      ]));
  set("valid_startroom", 1);
  set("outdoors","songjia");
  setup();
 
}
