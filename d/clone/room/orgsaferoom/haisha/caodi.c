
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵأ�һƬ����ӳ�����������˾��÷ǳ������һ���
ƣ���ƺ�һɨ���⡣������һ�����ң��Ǻ�ɳ���������Ϣ��˯���ĵ�
����
LONG);

  set("exits", ([ 
 "southup":__DIR__"suishilu",
 "northup":__DIR__"woshi",
 "west":__DIR__"lingwuroom"
      ]));
  set("valid_startroom", 1);
  set("outdoors","haisha");
  setup();
 
}
