
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�й�");
  set ("long", @LONG
���������Ԩ������ɽ������ס���й�����������¥�����ƷǷ���
���������ǻʵ۵��й���ֻ������ʱ��Ԩ��Ҫ������칫��ƽ��������
�Ǻ��ϣ���ƽ�������ǲ��ýӽ��й��ġ�
LONG);

  set("exits", ([ 
 "west":__DIR__"shangu",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

