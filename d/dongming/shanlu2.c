
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ·�����Ｘ��û��ʲô�ˣ�һƬ������ɪ�����ա�����
�Ӳݴ�����ֻ�м�ֻҰ�ò�ʱ����Ľ�ǰ�ܹ����������ߣ���Ҫ������
�ľ����ˡ�
LONG);
	set("exits", ([
		"southeast":__DIR__"shanlu1",
		"north":__DIR__"shanlu3",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

