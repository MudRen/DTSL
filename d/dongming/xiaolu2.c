
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С·�����Ｘ��û��ʲô������һ��紵������������
��ɳ��
LONG);
	set("exits", ([
		"southeast":"/d/wuyishan/shanjiao",
		"northwest":__DIR__"shalu1",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

