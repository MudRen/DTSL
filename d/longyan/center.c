// Room: /d/longyan/center.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������۴�����ļ��У����۴��Ǹ����Ĵ�壬����ÿ
��ũ��ʱ�������������Ǹϼ��ĵط���������һ�ð���Ĵ�
��������������ϰ�ߵĹ�����л����¡������߾��Ǽ����ˣ�
������һ��Сɽ·��������һ����������
LONG
	);
	set("outdoor", "1");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"field1",
  "east" : __DIR__"road2",
  "north" : __DIR__"road1",
  "west" : __DIR__"mktstr1",
]));

	setup();
	replace_program(ROOM);
}
