
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","����");
  set ("long", @LONG
������һƬ���֣�һƬ����ӳ�����������˾��÷ǳ������һ���
ƣ���ƺ�һɨ���⡣������һ�����ң��Ƿ���������������Ϣ��˯����
�ط���
LONG);

  set("exits", ([ 
 "westup":__DIR__"huayuan",
 "northeast":__DIR__"woshi",
 "south":__DIR__"lingwuroom"
      ]));
  set("valid_startroom", 1);
  set("outdoors","dajianglian");
  setup();
 
}
