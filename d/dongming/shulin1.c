
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
������Ƭ���֡��Ϸ������������������ɵ�ɽ�š��м��������ɵ�
���Ӵ��������˹���������̸����ʲô��
LONG);
	set("exits", ([
	     
		
		
		"south":__DIR__"door",
		"north":__DIR__"huayuan1",
		"east":__DIR__"shulin3",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

