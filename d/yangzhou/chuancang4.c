
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǻ����ϵĵĳ������м���������������æ��������ֻ������
�����˱ǣ��кܶ����õķ��˷����������ϡ��м�����������������̬
���ŵس��š�
LONG);
	set("exits", ([
		"east" :__DIR__"chuancang2",
	]));
	set("objects",([
	    __DIR__"npc/chuzi":1,
	    ]));
	set("resource/water",1);
	set("valid_startroom", 1);
	setup();
}
