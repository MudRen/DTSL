
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
��������߸������䳡��ֻ����������뱸������÷��׮��ɳ�ӵ�
����Ķ������м�����߸���������������ϰ���գ����ȵ�������ס��
������
LONG);

  set("exits", ([ 
 "east":__DIR__"lianwuchang",
 
      ]));
  set("valid_startroom", 1);
  set("outdoors","lifa");
  setup();
 
}
