
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����ݵ������ȡ������������ߣ�������ݵĳ�������Ϣ
���ˡ���������ݵ����������ȵ������ǲ���С�ĺɻ��أ�����ɻ�
ʢ�����ǳ�Ư����
LONG
);


	set("exits", ([
		"southwest" :__DIR__"xilang2",
                "east":__DIR__"zhengting",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
