
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��ʯ·"NOR);
	set("long", @LONG
��������ʯ·��������������ķ�ש��������һ����԰��������һ
��ľ�ݡ�����ǰ�߾���һ�������ˡ�
LONG);
	set("exits", ([
	     
		"north" :__DIR__"huayuan",
		"south":__DIR__"changlang1",
		"east":__DIR__"muwu3",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

