
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
���ǳ����ǵı����ţ���ǽ�����ż��Źٸ���ʾ���ٱ��Ǿ����ע
���Ź������ˣ������С��Ϊ�һ����ֱ����ʯ�����������졣��
����·����ͨ����ɽ����������ɽ���ǻ����˵ĵ����ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaolu5",
 "west":__DIR__"xiaolu4",
 "north":__DIR__"shandao6",
 "south":__DIR__"tydajie4",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
}

