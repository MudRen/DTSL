
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"�㷿"NOR);
	set("long", @LONG
�����Ǽ��㷿�����﹩�������������������ƣ��㲻�����������
�����ж��ˡ�
LONG);
	set("exits", ([
	     
		
		"west":__DIR__"shilu1",
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

