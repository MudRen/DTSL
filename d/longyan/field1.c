// Room: /d/longyan/field1.c

inherit ROOM;

void create()
{
	set("short", "���С·");
	set("long", @LONG
������һ����С·��������һ�������С����أ�΢��
����������з����������ˣ����Եĵ�����Ҳ���ҡ�ڣ�һƬ
��������侰��������ȥ��һ��Сľ�����������ؾ���
ũ�����˵ļ��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"woodhouse",
  "north" : __DIR__"center",
]));

	setup();
	replace_program(ROOM);
}
