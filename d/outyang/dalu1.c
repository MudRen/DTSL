
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����·");
  set ("long", @LONG
������һ�����Ĵ�·�������Թ��������Ƿ����ĵط�����������
��Ҳ�Ǻܶ࣬��Щ���֡��м�������Ů��̸Ц�Ŵ���������߹���˿��
����һ˿����ɬ֮�⡣
LONG);

  set("exits", ([ 
 "northwest":__DIR__"xiaolu4",
 "south":__DIR__"dalu2",
 "north":"/d/yangzhoubei/xiaolu1",
        ]));
  set("objects",([
          __DIR__"npc/nvzi":2,
          ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

