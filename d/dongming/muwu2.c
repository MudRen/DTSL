
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"ľ��"NOR);
	set("long", @LONG
������һ��ľ�ݡ������Ƕ��������ŵ��������ɻ�ĵط����кܶ�
�����ɵĵ���������ɻֻ����һ���������˽�����
LONG);
	set("exits", ([
	     
		
		"east":__DIR__"pinglu",
	
		]));
	set("objects",([
		__DIR__"npc/zhang_popo":1,
		]));

        
       set("valid_startroom", 1);   
  	setup();
       
       
}

