
inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է���
��ȥ�����ܵ��������������ࡣ
LONG);

	set("exits", ([
		"northeast" : __DIR__"tulu3",
		"southwest" : __DIR__"tulu1",
		"westup":"/d/emeishan/shanlu5",
	]));

	setup(); 
	replace_program(ROOM);
}
