
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�����߲�Զ���ǾŽ����ˡ�������������������
���Գ۹���һ����ֱ��ʯ����ͨ��ǰ����·�ϲ�ʱ�������������ĳ�
���������������ֳָ��ֱ�������������ϰ��֮�ˡ�
LONG);
	set("exits", ([
		"southeast":__DIR__"dalu7",
		"northwest":__DIR__"guanlu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

