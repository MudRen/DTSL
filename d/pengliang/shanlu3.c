#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���д�·");
	set("long", @LONG
����ɽ�����·����ǿ����ͨ��һ���󳵣�·��������������ĳ�
��ӡ��·��ɽ����ȫ�ǲ����ľ������ȥ�ܲ�͸�磬������ľ�������
ż��������в��ܴ��Ƽž�����·����������ת�˸��䡣
LONG );
	set("exits", ([
		"westdown"     : __DIR__"heyan",
		"southeast"     : __DIR__"xiaolu1",
	]));
	set("outdoors", "pingliang");
	setup();
	replace_program(ROOM);
}

