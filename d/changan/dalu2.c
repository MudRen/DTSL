
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·��������·������������˱Ƚ϶ࡣ��ʱ����̸
Ц�Ŵ���������߹���Ҳ�м���������ʿ������ȥ���������ƺ���Ͷ��
����������ġ�
LONG);

  set("exits", ([ 
"west":__DIR__"dalu1",
"southeast":__DIR__"shalu1",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

