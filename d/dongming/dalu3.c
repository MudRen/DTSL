
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ�����Ĵ�·������ľ�ɫ�ǳ��������㲻�����������
��ס�ˡ�
LONG);
	set("exits", ([
		"southwest":__DIR__"dalu2",
		"north":__DIR__"dalu4",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

