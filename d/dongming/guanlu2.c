
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�����߾��ǾŽ��������ˡ���������˺ܶࡣ����
�����������������Գ۹���һ����ֱ��ʯ����ͨ��ǰ����·�ϲ�ʱ
�������������ĳ����������������ֳָ��ֱ�������������ϰ��֮�ˡ�
LONG);
	set("exits", ([
		"southeast":__DIR__"guanlu1",
		"north":"/d/jiujiang/nanmen",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

