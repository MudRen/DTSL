
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"����"NOR);
  set ("long", @LONG
�����ǴȺ���ի�ĳ���������ǳ��徻����ǰ��һ������������
���ż�����ͷ�����м�����ˮ���㲻����Щ���ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"suishilu2",
     ]));
 set("no_fight",1);
  set("objects",([
	  __DIR__"obj/mantou":3,
	  __DIR__"npc/chuzi":1,
	  ]));
  set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

