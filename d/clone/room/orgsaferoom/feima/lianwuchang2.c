
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
 "west":__DIR__"lianwuchang",

      ]));
  set("valid_startroom", 1);
  set("outdoors","feima");
  setup();
 
}
