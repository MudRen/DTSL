
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����ݵ������ȡ����߾�����ݵĳ��������߾�����ݵ�
��Ϣ���ˡ���������ݵ����������ȵ������ǲ���С�ĺɻ��أ�����
�ɻ�ʢ�����ǳ�Ư����
LONG
);


	set("exits", ([
		"west" :__DIR__"huayuan",
		"north":__DIR__"chufang",
                "northeast":__DIR__"xilang1",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
