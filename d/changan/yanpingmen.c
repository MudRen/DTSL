
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ƽ��");
  set ("long", @LONG
���ǳ����ǵ���ƽ�ţ���ǽ�����ż��Źٸ���ʾ���ٱ��Ǿ����ע
���Ź������ˣ������С��Ϊ�һ����ֱ����ʯ���������졣
LONG);

  set("exits", ([ 
 "east":__DIR__"xpdajie1",
 "north":__DIR__"xiaolu2",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

