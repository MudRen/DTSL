
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ�����Ĵ�·�����߿�������ԼԼ�������ݵĳ�ǽ�ˡ���
����˺ܶ࣬����ǵ���������ġ�
LONG);
	set("exits", ([
		"south":__DIR__"dalu1",
		"northeast":__DIR__"dalu3",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

