// /d/taiyuan/road6.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG );
	set("exits", ([
	       "north" : "/d/mayi/xiaolu2",
		"southwest" : __DIR__"road5",
                "southeast" : __DIR__"road7",
	]));

	set("outdoors", "taiyuan");
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



