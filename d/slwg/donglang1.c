
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����ݵ������ȡ������������ߣ����������ϰ�书����
�����ˡ���������ݵ����������ȵ������ǲ���С�ĺɻ��أ�����ɻ�
ʢ�����ǳ�Ư����
LONG
);


	set("exits", ([
		"westup" :__DIR__"zhengting",
                "east":__DIR__"donglang2",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
