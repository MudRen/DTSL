
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����ݵ����ȡ��ϱ�����ݵĴ��š����߾�����ݵ�����
�ˡ��кܶ����������������ȥ���������ǳ����֡����߲�ʱ��������
�����������
LONG
);


	set("exits", ([
		"northup" :__DIR__"zhengting",
                "south":__DIR__"zoulang1",
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
