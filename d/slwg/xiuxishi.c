
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
��������ݵ�����Ϣ˯���ĵط���������źܶല���м������Ӵ�
������������ҵ������Ŵ���˯���ˡ������������죬�㲻�ɵ���Щ��
���ˡ�
LONG
);


	set("exits", ([
		"northeast" :__DIR__"huayuan",
		  
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("sleep_room",1);
       //set("outdoors", "slwg");
	setup();
}
