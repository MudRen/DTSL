inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
��������ǵ��ϳ��ţ���ǻ�����������֮�֣���˧��ռ��������
�󣬿�ʼ�ؽ���ǣ�������ž����½��ģ���Ȼ������ΰ����ȴ�ܼ�̣�
��ǽ��������ʯ�ݳɣ������ཬ��
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"north" : __DIR__"jiedao4",
		"south":"/d/yangzhoubei/shanlu13",
	]));
         set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	setup();
	replace_program(ROOM);
}

