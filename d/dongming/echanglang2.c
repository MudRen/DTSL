
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����"NOR);
	set("long", @LONG
�����Ƕ��ȡ��м��������ɵ��Ӵ�������ԴҴ��߹���������һƬ
�ݵأ��ϱ���һ����ͤ��ԶԶ���Կ���������ͤ���������֣��м�����
���ɵ��������������������
LONG);
	set("exits", ([
	     
		
		"north":__DIR__"caodi1",
		"west":__DIR__"echanglang1",
		"south":__DIR__"qingzhuting",
		
		
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

