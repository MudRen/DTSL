
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ·�������ǽ����ľ����ˡ���������˽�������������
�����Ӳݴ�����ֻ�м�ֻҰ�ò�ʱ����Ľ�ǰ�ܹ���
LONG);
	set("exits", ([
		"south":__DIR__"shanlu2",
		"northwest":__DIR__"shanlu4",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

