
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·�����߾��ǳ����ˣ����ϵĽ�ˮ��ʱ��������ԶԶ
��ȥ���ƺ��м�Ҷ������ʻ�ڽ�ˮ֮�С�
LONG);

  set("exits", ([ 
	  "south":__DIR__"shilu",
	  "west":__DIR__"tulu2",
	  "east":__DIR__"bingqifang",
    ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}