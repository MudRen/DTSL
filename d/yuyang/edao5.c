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
                "northeast" : __DIR__"edao4",
                "southeast" : __DIR__"edao8",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


