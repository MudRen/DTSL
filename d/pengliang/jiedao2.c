inherit ROOM;


void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
��������ǵ��ϱ������ɵ�����ǻ�����������֮�֣���˧��ռ��
�����Ժ󣬿�ʼ�ؽ���ǣ����̺����ڼ������ֵ������Է����еĸ�
�ս��ã��еĻ��ڼ��跿�ݵ����ܡ�
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"northeast" : __DIR__"jiedao1",
                "west" : __DIR__"gongdi1",
                 "east" : __DIR__"gongdi2",
                "southeast" : __DIR__"jiedao4",
	]));
	set("objects",([
	 __DIR__"npc/shaoshuaijun":1,
	 ]));
	setup();
	replace_program(ROOM);
}

