inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
���ǳǱ���һ��ɽ·��·�����ҵĳ�����ϥ�ĻĲݣ�Զ������һ�ˡ�
���Ըɿݵ������������˳�Ⱥ����ѻ���������������ڻ�Ұ��ԶԶ��ȥ��
һ�������ľ���
LONG );
	set("exits", ([
		"northeast" : __DIR__"edao5",
                "westup" : __DIR__"shanlu2",
	]));
	set("objects",([
     "/d/clone/npc/yuwenwudi":1,
     ]));
 	set("outdoors", "pengliang");
	setup();
	replace_program(ROOM);
}

