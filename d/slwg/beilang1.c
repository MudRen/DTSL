
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
		"north" :__DIR__"beilang2",
                "south":__DIR__"zhengting",
                "west":__DIR__"wuchang1",
                "east":__DIR__"wuchang2",
                
	]));
	set("objects",([
	     "/d/clone/npc/liguan":1,
	    ]));
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}

