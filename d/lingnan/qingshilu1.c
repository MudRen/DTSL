
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·�������м�ɽ��ˮ�ء���ɽ�Ϲ�ʯ��ᾣ�һ����֪
���Ը���֮�֡���ʱ��һЩ�μұ����Ӵ�������ԴҴ��߹���
LONG);

  set("exits", ([ 

  "south":__DIR__"donglang3",
  "north":__DIR__"qingshilu2",
       ]));
  set("objects",([
	  __DIR__"npc/song-shuang":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

