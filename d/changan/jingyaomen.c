
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ҫ��");
  set ("long", @LONG
���ǳ����ǵľ�ҫ�ţ���ǽ�����ż��Źٸ���ʾ���ٱ��Ǿ����ע
���Ź������ˣ������С��Ϊ�һ����ֱ����ʯ�����������졣
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaolu3",
 "south":__DIR__"tydajie2",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

