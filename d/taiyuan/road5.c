// /d/taiyuan/road5.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ����Ͼ����ÿ��ǡ����������̵ġ�
���Ŵ󳵵���������������ǳ����֡���ʱ����������������߷ɳ۶�
��������һ·������
LONG );
	set("exits", ([
                "south" : __DIR__"road7-1",
		"northeast" : __DIR__"road6",
		"southwest" : __DIR__"road4",
		
	]));
	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



