

inherit ROOM;


void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ�����������С·����������ǰ����������ɽ���غ�������
Ψһ·�������������Ѿ��޽������ĵ�·����Ȼ�ߵ���Ҳ�����ˡ�
LONG);
	
	set("exits", ([
		"north" : __DIR__"tulu2",
                "southwest" : __DIR__"eroad",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
