// Room: /d/longyan/woodhouse.c

inherit ROOM;

void create()
{
	set("short", "Сľ��");
	set("long", @LONG
����������һ��Сľ�ݣ���������һλ��ʮ������Ϻ�
��������Ƭ��ص����ˡ����������ʵ��һ��ľ��һ��ľ����
����Ψһ�ļҾߣ����ӽ������м��޸���������С��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"field1",
]));

	setup();
	replace_program(ROOM);
}
