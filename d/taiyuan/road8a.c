// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����ɽ��С·���о�·Խ��Խ���ˡ���ǰ��������ɽ����
���վ��������£��˳ơ�������ɽ����
LONG );
	set("exits", ([
		"northwest"  : __DIR__"road8b",
 		"southeast":"/d/huashan/shanlu1",
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



