
inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ڴ���ɽ���ϣ�ʯ�׶��ͣ�����Ŀǰ����ͷ��������ɽ���͵�
�֣���ľ������о��ס�
LONG
	);
	set("exits", ([
		"westup"  : __DIR__"cuiping2",
		"down"    : __DIR__"cuipinggu2",
	]));

	set("outdoors", "hengshan");
	setup();
        replace_program(ROOM);
}

