// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�������ɳ�ܴ���һ��С�ľ������۾���������
һ���۹أ�Ӧ�þ������������ļ����ء�
LONG );
	set("exits", ([
		"west"  : __DIR__"jiayuguan",
 		"east"  : __DIR__"road9",
        
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



