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
		"southwest" : __DIR__"edao7",
                "north" : __DIR__"nanmen",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


