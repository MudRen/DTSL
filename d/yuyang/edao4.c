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
		"southwest" : __DIR__"edao5",
		"northwest" : __DIR__"eroad5",
                "east" : __DIR__"ximen",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


