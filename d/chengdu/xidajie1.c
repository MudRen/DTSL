
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ�������֡�����ͨ�������ţ������ǳ����ģ��Ǳ��Ե÷�
�����֡��ֵ��ϱ���һ���������ſ������ǳ��ƾɣ����ϵ������Ѿ�
ģ�������ˡ�
LONG);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"west" : __DIR__"xidajie2",
		"east" : __DIR__"center",
		"south":__DIR__"simiao",
		"north": "/d/clone/room/cityroom/chengdu",
	]));
	set("objects",([
		__DIR__"npc/tongtian":1,
		]));

	setup();
	replace_program(ROOM);
}

