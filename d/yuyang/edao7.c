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
		"southwest" : __DIR__"chalu",
                "northeast" : __DIR__"edao6",
                "northwest" : __DIR__"shandao",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


