inherit ROOM;

void create()
{
	set("short", "��˧������");
	set("long", @LONG
������˧���Ĵ��ţ��Ű岻֪����ʲô�����Ƴɣ�����ȥ���һƬ��
�ƺ���Ϊ���أ��������������þ�����ͭ�����ڴ��ŵ���ǰ���и�����һ
���ߴ����ˣ������顸��˧�����������֡���ǰ�������߸�����������
����󵶵���˧���ٱ���
LONG );
        set("outdoors", "pengliang");

	set("exits", ([
		"west" : __DIR__"nandajie",
                "north" : __DIR__"yuanzi",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
        "/d/clone/npc/chvocation_npc":1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" &&
                objectp(present("song bing", environment(me))))
           return notify_fail("�ٱ�����ȵ���ʲô�˵����ô���˧����\n");

        return ::valid_leave(me, dir);
}
