
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ɽ"NOR);
  set ("long", @LONG
������һ����ɽ���˴���ɽ��״���أ���ϸ��ȥ����Լ���Ż�ɽ֮
�ˣ�̩ɽ֮ΰ����ɽ֮�ա���ɽ�ϻ���һ��С��ͤ��������˸����ң�
д�š�����ͤ����
LONG);

  set("exits", ([ 
  
  "north":__DIR__"huangchengnan",

  "south":__DIR__"changlang",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

