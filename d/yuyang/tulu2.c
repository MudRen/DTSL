
inherit ROOM;


void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ�����������С·����������ǰ����������ɽ���غ�������
Ψһ·�������������Ѿ��޽������ĵ�·����Ȼ�ߵ���Ҳ�����ˡ�����
������ϡ�٣�·���м��������ķ��ݡ�
LONG);
	
	set("exits", ([
		"north" : __DIR__"tulu3",
		"south" : __DIR__"tulu1",
                "southwest" : __DIR__"anle",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
