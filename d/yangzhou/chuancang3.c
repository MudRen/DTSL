
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��װ��");
	set("long", @long
�����Ǵ��ϵĻ�װ�ң�������Ů�ڲ�ױ��	
long);
	set("exits", ([
		"west" :__DIR__"chuancang2",
	]));
	set("objects",([
	    __DIR__"npc/wunv":2,
	    ]));
	set("valid_startroom", 1);
	setup();
}
