

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ͽ�����ʯ�ڶ�ֱ�����±�����һ����������������ƾ���
�ĺ�ɽɽ���У�ȴ����ʮ���������ڴ���ɽ������������Σ�ң�������
�ȣ��������£���������¥�Կ���ȽȽ���䡣�Ǿ����������ˡ�
LONG
	);
	set("exits", ([
		"up"         : __DIR__"cuiping1",
		"northwest"  : __DIR__"cuipinggu1",
	]));

	set("outdoors", "hengshan");
	setup();
        replace_program(ROOM);
}

