
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ�����Ĵ�·�������Ѿ����㽭�ľ����ˡ���������˽�
������������
LONG);
	set("exits", ([
		"south":__DIR__"tulu3",
		"north":__DIR__"dalu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

