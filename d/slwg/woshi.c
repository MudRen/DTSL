
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ���ʯ�������ң�������ʰ�ķǳ��ɾ������ӵ��������һ
�Ŵ󴲣���ͷ�Ϸ��ż�����ѧ���鼮��������ߵ�ǽ�Ϲ���һ�Ѹֽ���
ð����������
LONG
);


	set("exits", ([
		"west" :__DIR__"caodi",
                
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       //set("outdoors", "slwg");
	setup();
}
