
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�����������ȥ�������㽭������û��ʲô���ˡ�
�����Ӳݴ�����ֻ�м�ֻҰ�ò�ʱ����Ľ�ǰ�ܹ����Ա��м��ô�����
��֦�Ѿ����㣬������ɢ�����ż�ֻ��ѻ������������Ƶؽ��š�
LONG);
	set("exits", ([
		"south":__DIR__"chaguan",
		"northwest":__DIR__"shanlu5",
		"northeast":__DIR__"tulu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

