inherit ROOM;


void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
��������ǵ��ϱ������ɵ�����ǻ�����������֮�֣���˧��ռ��
�����Ժ󣬿�ʼ�ؽ���ǣ����̺����ڼ������ֵ������Է����еĸ�
�ս��ã��еĻ��ڼ��跿�ݵ����ܣ����洫�������Ĵ�������
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"north" : __DIR__"beichengmen",
                "south" : __DIR__"tiepu",
                 "southwest" : __DIR__"jiedao2",
                "southeast" : __DIR__"jiedao3",
	]));
	setup();
	replace_program(ROOM);
}

