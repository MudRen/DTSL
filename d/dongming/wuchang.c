
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"���䳡"NOR);
	set("long", @LONG
�����Ƕ����ɵ����䳡���кܶ������������ϰ���ա�ֻ��ߺ��֮
�ϲ��ϴ��������⽣Ӱ��һ�����ֵľ���
LONG);
	set("exits", ([
		"north":__DIR__"tingyuxuan",	
		"south":__DIR__"caodi1",		
	]));
	set("objects",([
		__DIR__"npc/shangbang":1,
		]));
     set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

