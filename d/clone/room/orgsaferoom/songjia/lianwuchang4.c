
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
 "south":__DIR__"lianwuchang",
      ]));
  set("valid_startroom", 1);
  set("outdoors","songjia");
  setup();
 
}
