
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
�����Ƿ������������䳡��ֻ����������뱸������÷��׮��ɳ��
������Ķ������м�������������������������ϰ���գ����ȵ�������
ס�Ĵ�����
LONG);

  set("exits", ([ 
 "south":__DIR__"huayuan",
 "east":__DIR__"lianwuchang2",
 "west":__DIR__"lianwuchang3",
 "north":__DIR__"lianwuchang4",
      ]));
  set("valid_startroom", 1);
  set("outdoors","feima");
  setup();
 
}
