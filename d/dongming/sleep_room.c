
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"��Ϣ��"NOR);
	set("long", @LONG
�����Ƕ����ɵ���Ϣ�ҡ����Ϸ��ż������죬�м��������ɵ�����
��������˯���������������������������Щ���ˡ�
LONG);
	set("exits", ([		
		"west":__DIR__"tingyuan",		
	]));
      set("sleep_room",1);
        
       set("valid_startroom", 1);   
     
	setup();
       
       
}

