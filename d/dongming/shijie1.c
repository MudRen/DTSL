
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ʯ��"NOR);
	set("long", @LONG
������һ���������ϵ�ʯ�ס����Ѿ����ڱ������С��������˺ܶ�
�ʻ������߻����˺ܶ�����
LONG);
	set("exits", ([
	     
		"southup" :__DIR__"shijie2",
		"northdown":__DIR__"door",
		
	]));
	
        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

