// /d/yuyang/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵���������������ǳ����֡���ʱ����������������߷�
�۶���������һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
		"north" : __DIR__"shanjiao",
                "south" : __DIR__"edao11",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


