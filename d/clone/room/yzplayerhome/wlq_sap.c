
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIC"������"NOR);
	set("long", @LONG
�����ǵ������ˡ��������Ů����������(sap)������(wlq)��
�������������ж����Ǹ���֮�С�ֻ���������һ�ŷ���������
�������ӣ������ϻ���һ���ո���õĲ�ˮ������������̫ʦ�Σ�
�м����һ�Ź��������񡣱�����һ�����ҡ�
LONG);
    set("exits", ([
	        "west" : __DIR__"nandajie3",
	        "north":__DIR__"sap_wlq_woshi",
	        "up":__DIR__"up_wlq_sap",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
