// /d/yuyang/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�ÿ�");
	set("long", @LONG
�ÿ������������֡���ƽ����������Ϊ�����������ǣ���߿���
������Ϊ�����������������֮�ף���Ϊ�������¾���ó�׵����ģ���
�ÿ��������λ��Ҳ�Ǳ��ұ���֮�ء�
LONG
	);

	set("exits", ([
                "south" : __DIR__"eroad3",
                "east" : __DIR__"shandao1",
                "northwest" : "/d/mayi/changcheng20",
	]));

 	set("outdoors", "/d/yuayng");
	setup();
	replace_program(ROOM);
}


