inherit ROOM;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
�������������ͷ�����˺���������ˮ�����������ｻ�㣬�Ǵ�
ֻת���ĵص㣬������ж�������������������������ϴ������ת�˴���	
LONG );

	set("exits", ([
               "southeast"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



