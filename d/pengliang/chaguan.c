inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű���
��һ���ſ��������˿��ˣ������̸��ս�֣���ͷ�Ӷ�����Ҫ�����
ʲô�����²���ʱ��
LONG );
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"beidajie",
	]));
	set("objects",([
	__DIR__"npc/xiaoer3":1,
	]));
	setup();
	replace_program(ROOM);
}

