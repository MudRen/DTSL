#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������Ǳ���֣��ֵ������ɾ�����ש����·�汻��ˮ��ù���
�羵���ֵ�������߷��ߴ����ΰ��˫�˺ϱ�������ʮ��һ�꣬�����
�������ߡ�
LONG );
	set("exits", ([
		"north" : __DIR__"beimen",
		"southwest" : __DIR__"xidajie",
		"southeast"  : __DIR__"dongdajie",
	]));
	set("objects",([
     "/d/clone/npc/yuwenshang":1,
     ]));
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

