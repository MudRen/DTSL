
inherit ROOM;


void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ�����������С·����������ǰ����������ɽ���غ�������
Ψһ·�������������Ѿ��޽������ĵ�·����Ȼ�ߵ���Ҳ�����ˡ�
LONG);
	
	set("exits", ([
		"northwest" : "/d/shanhaiguan/dadao2",
                "south" : __DIR__"tulu2",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
