inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
����ԭ������ǵĶ��������ɵ���һ���֣���ǻ�����������֮�֣�
��˧��ռ�������Ժ󣬿�ʼ�ؽ���ǣ����̺����ڼ�����������������
��æ����ͣ��
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
                "east" : __DIR__"jiedao2",
	]));
	setup();
	replace_program(ROOM);
}

