
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short",HIC"��ң��"NOR);
	set("long", @LONG
��������ң���ˡ��������Ů����������(jefferry)������
(devil) �������������ж����Ǹ���֮�С�ֻ���������һ�ŷ�
�������ż������ӣ������ϻ���һ���ո���õĲ�ˮ����������
��̫ʦ�Σ��м����һ�Ź��������񡣱�����һ�����ҡ�
LONG);
    set("exits", ([
	        "west" : __DIR__"nandajie2",
	        "north":__DIR__"jeffery_devil_woshi",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
