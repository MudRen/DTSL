// Room: /d/longyan/drugstore.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ��ҩ�̣���˵Զ�������׶������￴��������
�Ĵ�����ţ�������š��Ż�٢������˵ҽ���˵ã��Ǹ���
����ҽ�����������ʵ��������һ���⡰���ֻش�������
�������ҩ���ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mktstr2",
]));

	setup();
	replace_program(ROOM);
}
