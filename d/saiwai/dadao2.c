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
		"north" : __DIR__"dadao1",
		"southwest" : __DIR__"road1",
	]));
 	set("outdoors", "saiwai");
	setup();
	replace_program(ROOM);
}

