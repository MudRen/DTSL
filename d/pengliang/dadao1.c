inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����������Ĵ���ϡ������������������������ӵ����̣�
���Ŵ󳵵���������������ǳ����֡�������Ϊս�ҵ�ԭ�����Ѿ�����
�����������ˡ�
LONG
	);

	set("exits", ([
	        "west" :"/d/xingyang/dadao2",
                "southeast" : __DIR__"edao4",
                "northeast" : __DIR__"xiaolu1",
	]));

 	set("outdoors", "/d/penliang");
	setup();
	replace_program(ROOM);
}


