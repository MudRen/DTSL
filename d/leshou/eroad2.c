// /d/zhuojun/eroad2.c
// Room in �ÿ�
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡�
LONG );

	set("exits", ([
		"east"      : __DIR__"eroad3",
		"west"      : __DIR__"eroad1",
		
	]));

 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



