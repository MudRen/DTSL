
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɳ·");
	set("long", @LONG
������һ��ɳ·����ʱ�����������������Գ۹������Ｘ��û��
ʲô�ˣ�һƬ������ɪ�����ա�
LONG);
	set("exits", ([
		"southeast":__DIR__"xiaolu2",
		"north":__DIR__"shalu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

