
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���������ݳǵ����š����������Թž��Ƿ����ĳ��У�����������
���˺ܶࡣ�����м����ٱ����ڼ�����������ˡ�
LONG);

  set("exits", ([ 
 "northwest":__DIR__"nandajie3",
 "south":"/d/hangzhou/jiangbei",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

