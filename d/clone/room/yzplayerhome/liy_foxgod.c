
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIW"����"NOR);
	set("long", @LONG
�����������ˡ��������Ů������һ�磨LIY������������
��FOXGOD�����������������ж����Ǹ���֮�С�ֻ���������һ
�ŷ��������ż������ӣ������ϻ���һ���ո���õĲ�ˮ������
������̫ʦ�Σ��м����һ�Ź��������񡣱�����һ�����ҡ�
LONG);
    set("exits", ([
	        "west" : __DIR__"nandajie1",
	        "north":__DIR__"liy_foxgod_woshi",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
