// Room: /d/longyan/mktstr1.c

inherit ROOM;

void create()
{
	set("short", "���۴弯��");
	set("long", @LONG
����������۴�ļ���һ�����ˡ�һ������ɶ���������
�죬����������������ˮ����������������ֻ����·���Ե���
�ǽ�����С�������߾������۴�������ġ��������¡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/wiz/vocation",
  "east" : __DIR__"center",
  "west" : __DIR__"mktstr2",
]));

	setup();
	replace_program(ROOM);
}
