
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
�����Ǻ�ɳ������䳡��ֻ����������뱸������÷��׮��ɳ�ӵ�
����Ķ������м�����ɳ���������������ϰ���գ����ȵ�������ס��
������
LONG);

  set("exits", ([ 
 "northeast":__DIR__"suishilu",
 "north":__DIR__"lianwuchang2",
 "west":__DIR__"lianwuchang3",
 "south":__DIR__"lianwuchang4",
      ]));
  set("valid_startroom", 1);
  set("outdoors","haisha");
  setup();
 
}
