
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","��԰");
  set ("long", @LONG
������һ��԰���������˺ܶ໨�������Ƿ�������Ӣ������ϰ����
����Ϣ�ĵط���������һ�����䳡���ϱ���һ����������ʱ�з�������
���Ӵ������߹���
LONG);

  set("exits", ([ 
 "out":__DIR__"wanxiaotang",
 "north":__DIR__"lianwuchang",
 "southdown":__DIR__"chufang",
 "eastdown":__DIR__"zhulin",
      ]));
  set("valid_startroom", 1);
  set("outdoors","feima");
  setup();
 
}
