
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
����һ��Ρ��ĻʳǴ��ţ��߸ߵ���¥�Ϸ����š� ������ ��������
�ڻԻ͵Ĵ��֣��������������ͽ���ʳ��ˣ������ǰ��ϴ�֣�������
��������������ſڣ������˵�һ�ɲ���������
LONG);

  set("exits", ([ 
 "west":__DIR__"shaofujian",
 "east":"/d/changan/asdajie4",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

