inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š�����������֡��ٱ��Ǿ���
��ע���Ź������ˣ������С��Ϊ�һ����ֱ����ʯ����������
�����졣
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"west" : __DIR__"dongdajie",
                "east" : __DIR__"edao1",
	]));
         set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
    
	]));
	setup();
	replace_program(ROOM);
}

