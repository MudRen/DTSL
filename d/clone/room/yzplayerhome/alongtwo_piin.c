
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIY"������"NOR);
	set("long", @LONG
�����Ǳ������ˡ��������Ů������ʲô������(alongtwo)
�ͻ��칤(piin) �������˶��Ը��͵��书����������֮�С� ֻ
���������һ�ŷ��������ż������ӣ������ϻ���һ���ո����
�Ĳ�ˮ������������̫ʦ�Σ��м����һ�Ź��������񡣱�����
һ�����ҡ�
LONG);
    set("exits", ([
	        "east" : __DIR__"nandajie2",
	        "south":__DIR__"alongtwo_piin_woshi",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
