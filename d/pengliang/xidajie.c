// /d/qiuci/xidajie1
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������̼����ڣ�
��������������ʮ�����֡�������������ʮ�ֽֿڡ��ϱ���һ�ҵ��̣�
������һ��Ǯׯ��
LONG
	);
        set("outdoors", "pengliang");

	set("exits", ([
		"east" : __DIR__"shizijietou",
		"south" : __DIR__"dangpu",
                "north" : __DIR__"qianzhuang",
		"west" : __DIR__"ximen",
		
	]));

	setup();
	replace_program(ROOM);
}

