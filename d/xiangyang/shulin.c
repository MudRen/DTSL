
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա��ʻ��̲��������֣�
����ɽ���ﴵ����������磬������������������һЩ�����Ļ��㣬����
�侳�����ӡ��ľ�֮����Ȼ������
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shulin1",
  "south":__DIR__"caodi3",
         ]));

  set("valid_startroom", 1);
  set("outdoors","xiangyang");
  setup();
 
}

