

inherit ROOM;

void create()
{
	set("short", "����С�Ե�");
	set("long", @LONG
�����Ǽ�С�Եꡣ��ǰ�Ļ����ڷ���ҡ�ڲ�������Զ�Ϳ��������
�������ڳɶ�����û���ܵ�ս�ҵĸ��ţ������������⻹�Ǻܲ�����
С�������ſ��к����������ˡ�
LONG);
        //set("outdoors", "�ɶ�");

	set("exits", ([
	
	
		"south" : __DIR__"dongdajie2",
	]));
	set("objects",([
		__DIR__"npc/xiaoer":1,
		]));

	setup();
	replace_program(ROOM);
}

