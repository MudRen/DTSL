
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
����һ��С�����������ۣ���֪����ͨ��ʲô�ط���������Щ������
�㲻��С��������
LONG
	);


	set("exits", ([
		"south" :__DIR__"xiaojing",
		"west":__DIR__"fendi",
	]));
       set("outdoors", "�ɶ�");
	setup();
}

