
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ϲ��");
  set ("long", @LONG
����һ��Ρ��ĻʳǴ��ţ��߸ߵ���¥�Ϸ����š� ��ϲ�� ��������
�ڻԻ͵Ĵ��֣��������������ͽ���ʳ��ˣ������ǰ��ϴ�֣�������
��������������ſڣ������˵�һ�ɲ���������
LONG);

  set("exits", ([ 
 "west":__DIR__"hggc3",
 "east":"/d/changan/asdajie5",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

