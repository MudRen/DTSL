inherit ROOM;


void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
��������ǵ��ϱ������ɵ�����ǻ�����������֮�֣���˧��ռ��
�����Ժ󣬿�ʼ�ؽ���ǣ����̺����ڼ������ֵ������Է����еĸ�
�ս��ã��еĻ��ڼ��跿�ݵ����ܡ����洫����е�������
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"north" : __DIR__"mafang",
                "south" : __DIR__"nanchengmen",
                 "northwest" : __DIR__"jiedao2",
                "northeast" : __DIR__"jiedao3",
	]));
	set("objects",([
	 __DIR__"npc/gongren":1,
	 ]));
	setup();
	replace_program(ROOM);
}

