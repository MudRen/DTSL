
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"�ݵ�"NOR);
	set("long", @LONG
������һƬ�ݵء������Ƕ�����������������Ǹ�ʯ�ס��м�����
�ܴ�������ԴҴ��߹��������ߵ�ʯ����ȥ��
LONG);
	set("exits", ([
	     
		
		"northup":__DIR__"shijie4",
	
		"south":__DIR__"tingyuxuan",
		
		
	]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

