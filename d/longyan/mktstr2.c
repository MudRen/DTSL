// Room: /d/longyan/mktstr2.c

inherit ROOM;

void create()
{
	set("short", "���۴弯��");
	set("long", @LONG
����������۴�ļ���һ�����ˡ�һ������ɶ���������
�죬����������������ˮ����������������ֻ����·���Ե���
�ǽ�����С���������ǡ������á�ҩ�̣����������Զ������
�ġ��м��ջ���ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hotel",
  "east" : __DIR__"mktstr1",
  "north" : __DIR__"drugstore",
]));

	setup();
	replace_program(ROOM);
}
