inherit ROOM;
void create()
{
	set("short", " ��ʯ·");
	set("long", @LONG
����һ����ʯ·���ֵ������ɾ�����ש����·�汻��ˮ��ù���
�羵���ֵ�������߷��ߴ����ΰ��˫�˺ϱ�������ʮ��һ�꣬�����
�������ߡ�����һ�Դ��������������������ԡ�������ǳ���Ԫ˧����
��������м��ҵ��̣��ֵ��е����塣
LONG );
	set("exits", ([
		"north" : __DIR__"gate",
		"west"  : __DIR__"liyang",
		"east"  : __DIR__"junying",
		"south":__DIR__"yanju",
	]));
	set("no_clean_up", 0);
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}
