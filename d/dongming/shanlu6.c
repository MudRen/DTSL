
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�������Ѿ��ǽ����ľ����ˡ����Ŀ����������Ϊ
��Χ�ľ�ɫ������ס�ˡ�
LONG);
	set("exits", ([
		"southeast":__DIR__"shanlu5",
		"north":__DIR__"dalu5",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

