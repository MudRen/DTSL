
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�����������ߣ������㽭�ľ����ˡ���������˽�
������������
LONG);
	set("exits", ([
		"south":__DIR__"tulu2",
		"north":__DIR__"dalu1",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

