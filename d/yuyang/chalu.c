// /d/yuyang/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
���ߵ�һ������·�ڣ�����ͨ�������Ĵ�·�������߾�Ҫ����
���ٵĵؽ��ˣ��������Ҫ����ɽ���ĵؽ��ˡ�
LONG
	);

	set("exits", ([
                "southwest" : __DIR__"edao13",
                "northeast" : __DIR__"edao7",
                "southeast" : "/d/leshou/dadao1",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


