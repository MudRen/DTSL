
inherit ROOM;
#include <ansi.h>

void create()	
{
	set("short",HIB"����"NOR);
	set("long", @LONG
������һ�����ҡ�������һ�����ڡ�����ڶ����ģ�ʲôҲ������
����
LONG);
    set("exits", ([
	        "up" : __DIR__"woshi",
	]));
   set("objects",([
      __DIR__"obj/mask":1,
      ]));
 	  setup();
	
}

