
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
���������ȡ����ȵ�ǽ���ϻ���һЩ�����ıڻ����������ʼ�������
���ǳ�����������֮�֡�������һ�����֡�
LONG);
	set("exits", ([	     		
		"east":__DIR__"changlang1",
		"west":__DIR__"zhulin",				
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

