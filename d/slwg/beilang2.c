
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������ʯ����ݵı����ȡ������������ߣ��Ϳ��Ե�ʯ�����鷿��
�����ˡ��ϱ�����ݵ����������ȵ������ǲ���С�ĺɻ��أ������
��ʢ�����ǳ�Ư����
LONG
);


	set("exits", ([
		"northeast" :__DIR__"jiashan",
                "south":__DIR__"beilang1",
                "east":__DIR__"liaoshangshi",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}
