
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
���������֡����̵�������΢��Ĵ����²�ס�ζ�������ɳɳ����
����������һ��ͥԺ��
LONG);
	set("exits", ([	     				
		"south":__DIR__"tingyuan",
		"northeast":__DIR__"zhulin",				
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

