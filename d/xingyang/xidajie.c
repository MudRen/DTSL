inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������ڶ����ĵ������ߡ�����ɫɫ�Ľ������ڶ��ߴ���˷���
���಻����·�ϳ�ˮ��������ɫ����Ħ����࣬���ַǷ���
LONG );

	set("exits", ([
                         "west"      : __DIR__"ximen",
                         "east"      : __DIR__"center",
                         "north":__DIR__"yanju",
		
	]));


 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



