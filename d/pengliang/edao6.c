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
		"southeast" : __DIR__"edao5",
		"north" : __DIR__"edao7",
	]));
	set("objects",([
     "/d/clone/npc/yuwenchengdu":1,
     ]));
 	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

