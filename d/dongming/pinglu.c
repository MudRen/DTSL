
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"С·"NOR);
	set("long", @LONG
�㵽��һ��ƽ̹֮�����������ŷ�ש��һֱͨ��ǰ�����ϱ���һ��
ʯ�ס�������һ��ľ�ݡ�
LONG);
	set("exits", ([
	     
		
		"west":__DIR__"muwu2",
	
		"southdown":__DIR__"shijie5",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

