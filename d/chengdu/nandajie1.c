
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
���ǳɶ����ϴ�֡��ϱ�ͨ���ϳ��ţ������ǳ����ģ����ﴫ����
���ֵ��������ɶ��⼸��ۼ��˺ܶ�������ʿ�����Զ�����ȻҲ�ɳ�
�˺ܶ���ӳ���Ѳ�ӡ�Զ���м������𱤵ĵ������ڳ�����������
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"south" : __DIR__"nandajie2",
		"north" : __DIR__"center",
		"east" : __DIR__"qingyang",
	]));
  
	set("objects",([
		__DIR__"npc/fanzhuo":1,
		]));
	setup();
	replace_program(ROOM);
}

