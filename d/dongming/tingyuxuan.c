
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"������"NOR);
	set("long", @LONG
�����ǡ�����������ƽʱ�����ж����ɵ�����������Ϣ����������
��һ�����������������ߣ�������˼���ּ����㣬��Ȼ�������Ѿ�ʱ
���Ѿã�����Ȼ��ɫ���ʡ�
LONG);
	set("exits", ([	     		
		"north":__DIR__"caodi2",	
		"south":__DIR__"wuchang",				
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

