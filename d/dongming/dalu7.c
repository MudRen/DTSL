
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�����������������������Գ۹���һ����ֱ��ʯ
����ͨ��ǰ����·�ϲ�ʱ�������������ĳ����������������ֳָ�
�ֱ�������������ϰ��֮�ˡ�
LONG);
	set("exits", ([
                "south":__DIR__"dalu6",
		"northwest":__DIR__"guanlu1",
   "north":"/d/quest/yrs/heidian",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

