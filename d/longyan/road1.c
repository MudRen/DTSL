// Room: /d/longyan/road1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·������ͨ��Բ�������Ĵ�ׯ��������
�壬�������Ϻ���ɽ��·��ɽ·��̫���ߣ�ǰ���ƺ���һ��С
ͤ��������һ�ȴ��ţ�����װ���ʮ���ִ������������ҵ�
�ǼǴ���Ҳ�������������ʵ�����ӵ㡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"center",
  "north" : __DIR__"tenting",
  "west" : "/d/wiz/check",
]));

	setup();
	replace_program(ROOM);
}
