
inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
���ǳɶ���һ������ƽʱ�кܶ������������ݷ����ս����
����û�ж������������ˡ�Ժ�ӵ�������һ������¯������Ѿ�ʮ�ֱ�
�䣬�ܾ�û������ˡ������Ǽ����ƾɵ��᷿�������Ѿ��ܾ�û���˾�
ס�ˡ�
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"north":__DIR__"xidajie1",
		"enter":__DIR__"dadian",
	]));

	setup();
	replace_program(ROOM);
}

