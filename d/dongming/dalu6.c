
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·����������˽�������������һ����ֱ��ʯ����
ͨ��ǰ�������ܿ�ʼ��һЩ���ӵ�����������
LONG);
	set("exits", ([
		"south":__DIR__"dalu5",
		"north":__DIR__"dalu7",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

