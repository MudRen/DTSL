inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ���������
����������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬
Ϊƽ̹�Ĵ�������˼�����͵����ߡ�·�����˽���ϡ��������
LONG );
	set("exits", ([
		"northeast":__DIR__"edao2",
		"west":__DIR__"dongmen",
	]));

 	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

