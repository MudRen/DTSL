
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIB"̶ˮ��"NOR);
  set ("long", @LONG
�������ٲ������̶ˮ�����洩���ٲ�ˮ��ĺ�����������ȴ�ǳ�
�ž����������γ������Աȡ��м��������������������ȥ��
LONG);

  set("exits", ([ 
 "up":__DIR__"shui",
     ]));
 if(sizeof(children(__DIR__"obj/bifengjian"))<2)
  set("objects",([
	  __DIR__"obj/bifengjian":1,
	  "/d/clone/npc/beast/eyu":1,
	  ]));
set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}

