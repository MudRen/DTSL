
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","���䳡");
  set ("long", @LONG
�����Ƕ��𱤵����䳡��ֻ����������뱸������÷��׮��ɳ�ӵ�
����Ķ������м������𱤵�������������ϰ���գ����ȵ�������ס��
������
LONG);

  set("exits", ([ 
 "west":__DIR__"lianwuchang",

      ]));
  set("valid_startroom", 1);
  set("outdoors","dunzunbao");
  setup();
 
}
