inherit ROOM;

void create()
{
	set("short", "��˧����Ժ");
	set("long", @LONG
��������˧���Ĵ�Ժ��ֻ������ʯ�̾͵ĵ���һ����Ⱦ����������
���ʵ�СѾ��������ڲ�ϴ���ߵ����˺����ӣ���ʱ��ֵ�����ʿ�߹�
����������ȥ�����Կ�����˧���Ĵ�����
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}

