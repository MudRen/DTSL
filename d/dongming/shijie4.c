
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ʯ��"NOR);
	set("long", @LONG
������ʯ�ס������кܶ������������ȥ���ƺ���æ��Щʲô����
�����˺ܶ��ʻ������߻����˺ܶ�����
LONG);
	set("exits", ([
	     
		
		"northup":__DIR__"shijie5",
	
		"southdown":__DIR__"caodi2",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}
