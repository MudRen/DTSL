#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�����������֣��ֵ������ɾ�����ש����·�汻��ˮ��ù���
�羵���ֵ�������߷��ߴ����ΰ��˫�˺ϱ�������ʮ��һ�꣬�����
�������ߡ���������м��ҵ��̣��ֵ��е����塣
LONG );
	set("exits", ([
		"north" : __DIR__"jiuguan",
		"northeast" : __DIR__"beidajie",
		"southeast"  : __DIR__"westdao",
                "west" : __DIR__"ximen",
	]));
	set("objects",([
     "/d/clone/npc/yuwenshiji":1,
     ]));
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

