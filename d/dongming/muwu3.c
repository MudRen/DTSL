
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ľ��"NOR);
	set("long", @LONG
������һ��ľ�ݡ����Ƕ�����Ů���Ӿ�ס�ĵط������ϵı������
�������롣����ɢ���ŵ�����������
LONG);
	set("exits", ([
	     
		
		"west":__DIR__"shilu2",
	
		]));
       
       set("valid_startroom", 1);   
      // set("outdoors", "��ʯ·");  
	setup();
       
       
}

