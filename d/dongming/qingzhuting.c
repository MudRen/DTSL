
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"����ͤ"NOR);
	set("long", @LONG
����������ͤ���������˺ܶ������ƽʱ�������˵�����������
����һ��������������ڽ�  ��˼�ζΡ���
LONG);
	set("exits", ([
	     
		
		"north":__DIR__"echanglang2",
		"south":__DIR__"baiyuanshi",						
	]));
       set("objects",([
          __DIR__"npc/shanqing":1,
          ]));
        
       set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

