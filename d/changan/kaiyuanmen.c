
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Զ��");
  set ("long", @LONG
���ǳ����ǵĿ�Զ�ţ���ǽ�����ż��Źٸ���ʾ���ٱ��Ǿ����ע
���Ź������ˣ������С��Ϊ�һ����ֱ����ʯ���������졣
LONG);

  set("exits", ([ 
 "east":__DIR__"tydajie1",
 "south":__DIR__"xiaolu1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

