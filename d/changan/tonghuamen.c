
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ͨ����");
  set ("long", @LONG
���ǳ����ǵ�ͨ���ţ���ǽ�����ż��Źٸ���ʾ���ٱ��Ǿ����ע
���Ź������ˣ������С��Ϊ�һ����ֱ����ʯ�����������졣
LONG);

  set("exits", ([ 
 "west":__DIR__"tydajie8",
  "south":__DIR__"xiaolu0",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

