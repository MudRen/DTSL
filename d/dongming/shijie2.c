
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ʯ��"NOR);
	set("long", @LONG
������һ���������ϵ�ʯ�ס�������촵������е�һ�����ˬ��
�������˺ܶ��ʻ������߻����˺ܶ�����
LONG);
	set("exits", ([
	     
		"southup" :__DIR__"shijie3",
		"northdown":__DIR__"shijie1",
		
	]));
	
        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

