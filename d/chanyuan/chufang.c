
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǿ�����Ժ�ĳ�������Ժ�ĵ��Ӿ�������Է����м�����ͷ
����������������ǰ��������Ϸ��ż����׷����Ա߻����ż�����ˮ��
LONG);

  set("exits", ([ 
	  "east":__DIR__"xiaolu5",
    ]));
  set("objects",([
	  __DIR__"obj/rice":4,
	  "/d/clone/npc/chuzi":1,
	  ]));
  set("resource/water",1);

  
  set("valid_startroom", 1);
  setup();
 
}

