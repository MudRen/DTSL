inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣������һ��ݣ�һ��
���顰�衱������ڷ��������ҡҷ�ţ�һ�ɹɲ������������������
�����ı�Ӫ���������������洫���Ĳ�������
LONG );
        set("outdoors", "pengliang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"shizijietou",
		"west"  : __DIR__"junying",
		"north" : __DIR__"beimen",
	]));
	setup();
	replace_program(ROOM);
}

