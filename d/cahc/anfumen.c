
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
����һ��Ρ��ĻʳǴ��ţ��߸ߵ���¥�Ϸ����š� ������ ��������
�ڻԻ͵Ĵ��֣��������򶫣��ͽ���ʳ��ˣ������ǰ�����֣�������
��������������ſڣ������˵�һ�ɲ���������
LONG);

  set("exits", ([ 
 "east":__DIR__"hggc1",
 "west":"/d/changan/ahdajie5",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":2,
          "/d/cahc/npc/yanli":1,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

