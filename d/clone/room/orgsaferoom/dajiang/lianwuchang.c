
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
�����Ǵ��������䳡��ֻ����������뱸������÷��׮��ɳ�ӵ�
����Ķ������м���������������������ϰ���գ����ȵ�������ס��
������
LONG);

  set("exits", ([ 
 "eastup":__DIR__"suishilu",
 "north":__DIR__"lianwuchang2",
 "west":__DIR__"lianwuchang3",
 "south":__DIR__"lianwuchang4",
      ]));
  set("valid_startroom", 1);
  set("outdoors","dajianglian");
  setup();
 
}
