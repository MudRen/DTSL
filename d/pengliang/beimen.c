inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
���Ǳ����ţ��������Ϸ����š����š�����������֡��ٱ��Ǿ���
��ע���Ź������ˣ������С��Ϊ�һ����ֱ����ʯ�������ϱ���
�����졣
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"north" : __DIR__"edao5",
                "south" : __DIR__"beidajie",
	]));
         set("objects", ([
		__DIR__"npc/bing" : 2
	]));
	setup();
	replace_program(ROOM);
}

