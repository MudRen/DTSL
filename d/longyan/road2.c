// Room: /d/longyan/road2.c

inherit ROOM;

void create()
{
	set("short", "���۴�ֵ�");
	set("long", @LONG
������һ���ž��Ĵ��С����Զ�뼯�е���������·����
����ͨ��ũ����������һ������̡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"center",
]));

	setup();
	replace_program(ROOM);
}
