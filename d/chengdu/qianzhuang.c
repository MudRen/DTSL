
inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
���ǳɶ���һ��������Ǯׯ������������ܺã�������������ı�
�����ң�����Ǯ����Ҳ�Ͳ����ˡ��ϰ����ڹ�̨���ô����̣��������
�������£��е������죬�е�ſ�������ϴ��ź�Ƿ�����ź�Ƿ��
LONG
	);
	set("exits", ([
		"north" : __DIR__"xidajie2",
	]));
	set("objects",([
		__DIR__"npc/zhang":1,
		]));
	setup();
	replace_program(ROOM);
}

