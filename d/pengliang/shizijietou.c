// /d/pengliang/shizijietou
//room in ����
inherit ROOM;

void create()
{
	set("short", "ʮ�ֽ�ͷ");
	set("long", @LONG
�����������������ģ�һ�����������Ĺ㳡��������ʯ���档ԭ��
�����������У�һ�ɷ������󣬵������´�����������������ս��֮�࣬
����˧���������������������ö��ˡ�
LONG
	);
        set("outdoors", "/d/pengliang");
       
	set("exits", ([
		"east" : __DIR__"dongdajie",
		"south" : __DIR__"nandajie",
		"west" : __DIR__"xidajie",
		"north" : __DIR__"beidajie",
	]));
set("objects", ([
		__DIR__"npc/putou" : 1,
                __DIR__"npc/guanyuan" : 1,
	]));
	setup();
}

// laowuwu 99/03/28
