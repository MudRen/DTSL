
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����������ĵط��ˡ����ߡ��ϱߡ�������������������
ʯ����ݵĵ��Ӿ�����������ϰ���ա���ʱ�����ﴫ�����ȵ�������
�������ǳ����֡�
LONG
);


	set("exits", ([
		"northwest" :__DIR__"donglang2",
                "east":__DIR__"liangongfang2",
                "north":__DIR__"liangongfang1",
                "south":__DIR__"liangongfang3",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
      // set("outdoors", "slwg");
	setup();
}
