
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
�����Ƕ��ȡ�ǽ���Ͽ���һЩͼ������������������������������
����������������һ�����ǳ���������֮�֡��㲻���������Ļ�������
����
LONG);
	set("exits", ([	     		
		"east":__DIR__"echanglang2",
		"west":__DIR__"changlang1",
		"north":__DIR__"dawuzi",
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

