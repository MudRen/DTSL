
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǿ��ǳɶ����ϳ����ˡ��ɶ��ش����У�һ������ս�����ţ���
�Ժ��ټ�����ʿ����
LONG);


	set("exits", ([
		"north" : __DIR__"nandajie2",
    	"south" : __DIR__"tulu3",
	]));
	set("object",([
		__DIR__"npc/bing":2,
		]));
        set("outdoors", "�ɶ�");
	setup();
}



