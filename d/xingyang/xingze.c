inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������˺ӵ�����һ��һ����ʵ���Ƕ���Ϊһ���������
�����Ĵ���ͷ���Ǵ�ֻת���ĵص㣬�����������ϴ������ת�˴�����
���ˮ�ʹ��˺����ʽ��㴦��	
LONG );

	set("exits", ([
               "southwest"      : __DIR__"qingshilu2",
               "east"      : __DIR__"qingshilu3",
               "southeast"      : __DIR__"guanlu2",
               "northwest"      : __DIR__"matou",
		
	]));

 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



