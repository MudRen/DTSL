
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"�ݵ�"NOR);
	set("long", @LONG
������һƬ�ݵء������Ƕ����ɵ����䳡���ϱ���һ�����ȡ�����
������������䳡ߺ�ȵ��������������Ӵ������ߴҴҶ�����
LONG);
	set("exits", ([
	     
		
		"north":__DIR__"wuchang",
	
		"south":__DIR__"echanglang2",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

